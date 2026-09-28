import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import '../engines/story_engine.dart';
import '../engines/save_manager.dart';
import '../pages/story_page.dart';
import '../pages/flow_map_page.dart';

/// =====================================================
/// 🖼️ 主页背景图片配置
/// =====================================================
/// 将此处的文件名改为你放在 assets/images/backgrounds/ 下的图片即可。
/// 设为 null 则使用渐变色背景。
/// 示例: 'home_bg.png', 'menu_background.jpg', null
/// =====================================================
const String? kHomeBackgroundImage = 'bg_home.png';

/// MyGO 应用入口组件
/// 负责初始化引擎、加载数据、读取存档并显示启动菜单
class MygoApp extends StatelessWidget {
  const MygoApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'MyGO 决策模拟器',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        brightness: Brightness.dark,
        primarySwatch: Colors.purple,
        scaffoldBackgroundColor: const Color(0xFF0D0221),
        fontFamily: null, // 使用默认字体，可配置 NotoSansSC
      ),
      home: const _StartupScreen(),
    );
  }
}

/// 启动屏幕
/// 负责初始化引擎、加载存档，并让用户选择"继续游戏"或"重新开始"
class _StartupScreen extends StatefulWidget {
  const _StartupScreen();

  @override
  State<_StartupScreen> createState() => _StartupScreenState();
}

class _StartupScreenState extends State<_StartupScreen> {
  final StoryEngine _engine = StoryEngine();
  final SaveManager _saveManager = SaveManager();
  bool _isLoading = true;
  bool _hasSaveData = false;
  String? _errorMessage;

  @override
  void initState() {
    super.initState();
    _initialize();
  }

  /// 初始化：加载剧情数据并检查存档
  Future<void> _initialize() async {
    try {
      await _engine.loadFlowData();
      final hasSave = await _saveManager.hasSaveData();

      // 加载已解锁结局
      final unlockedEndings = await _saveManager.loadUnlockedEndings();

      if (mounted) {
        setState(() {
          _hasSaveData = hasSave;
          _endingsCount = unlockedEndings.length;
          _isLoading = false;
        });
      }
    } catch (e) {
      if (mounted) {
        setState(() {
          _errorMessage = '加载数据失败: $e';
          _isLoading = false;
        });
      }
    }
  }

  /// 继续游戏（从存档恢复）
  Future<void> _continueGame() async {
    final savedState = await _saveManager.loadGame();
    if (savedState == null) {
      // 存档异常，启动新游戏
      _startNewGame();
      return;
    }

    // 将已解锁结局合并到恢复的状态中
    final unlockedEndings = await _saveManager.loadUnlockedEndings();
    for (final id in unlockedEndings) {
      if (!savedState.unlockedEndings.contains(id)) {
        savedState.unlockedEndings.add(id);
      }
    }

    _enterGame(savedState);
  }

  /// 开始新游戏
  void _startNewGame() {
    final emptyState = null; // 不传入存档，引擎自行初始化
    _engine.startNewGame();
    _enterGame(null);
  }

  /// 进入游戏主页面
  Future<void> _enterGame(dynamic savedState) async {
    if (savedState != null) {
      _engine.restoreFromState(savedState);
    } else {
      // 如果还没初始化则初始化
      if (_engine.currentNode == null) {
        _engine.startNewGame();
      }
    }

    // 使用 push 而非 pushReplacement，保留启动页在路由栈底
    // 故事页可通过 Navigator.pop(context) 回到主页
    await Navigator.of(context).push(
      MaterialPageRoute(
        builder: (_) => ChangeNotifierProvider.value(
          value: _engine,
          child: const StoryPage(),
        ),
      ),
    );

    // 从故事页返回后刷新存档与结局状态
    if (mounted) {
      _refreshFromSave();
    }
  }

  /// 从存档刷新状态（返回主页时调用）
  Future<void> _refreshFromSave() async {
    final hasSave = await _saveManager.hasSaveData();
    final unlockedEndings = await _saveManager.loadUnlockedEndings();
    if (mounted) {
      setState(() {
        _hasSaveData = hasSave;
        _endingsCount = unlockedEndings.length;
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Stack(
        children: [
          // ===== ① 渐变底层（始终显示，背景图缺失时可见） =====
          Container(
            decoration: const BoxDecoration(
              gradient: LinearGradient(
                colors: [
                  Color(0xFF0D0221),
                  Color(0xFF1A0A3E),
                  Color(0xFF2D1B69)
                ],
                begin: Alignment.topCenter,
                end: Alignment.bottomCenter,
              ),
            ),
          ),

          // ===== ② 可配置主页背景图（在渐变之上） =====
          // 修改文件顶部 kHomeBackgroundImage 常量即可切换背景
          if (kHomeBackgroundImage != null)
            Positioned.fill(
              child: Image.asset(
                'assets/images/backgrounds/$kHomeBackgroundImage',
                fit: BoxFit.cover,
                width: double.infinity,
                height: double.infinity,
                errorBuilder: (_, __, ___) => const SizedBox.shrink(),
              ),
            ),

          // ===== ③ 暗色蒙层（增强文字可读性） =====
          Container(
            color: Colors.black.withOpacity(
              kHomeBackgroundImage != null ? 0.55 : 0.0,
            ),
          ),

          // ===== ④ 粒子装饰（可选氛围效果） =====
          if (kHomeBackgroundImage == null)
            Positioned.fill(
              child: _buildAtmosphereParticles(),
            ),

          // ===== ⑤ 主内容 =====
          Center(
            child: _isLoading
                ? _buildLoading()
                : _errorMessage != null
                    ? _buildError()
                    : _buildMenu(),
          ),
        ],
      ),
    );
  }

  /// 构建氛围粒子装饰（无背景图时显示光点）
  Widget _buildAtmosphereParticles() {
    return CustomPaint(
      painter: _ParticlePainter(),
    );
  }

  /// 加载中
  Widget _buildLoading() {
    return const Column(
      mainAxisSize: MainAxisSize.min,
      children: [
        CircularProgressIndicator(color: Color(0xFFFF6B9D)),
        SizedBox(height: 20),
        Text(
          '正在加载剧情数据…',
          style: TextStyle(color: Colors.white70, fontSize: 16),
        ),
      ],
    );
  }

  /// 错误提示
  Widget _buildError() {
    return Padding(
      padding: const EdgeInsets.all(32),
      child: Column(
        mainAxisSize: MainAxisSize.min,
        children: [
          const Icon(Icons.error_outline, color: Colors.red, size: 64),
          const SizedBox(height: 16),
          Text(
            _errorMessage!,
            style: const TextStyle(color: Colors.white70, fontSize: 14),
            textAlign: TextAlign.center,
          ),
          const SizedBox(height: 24),
          ElevatedButton(
            onPressed: () {
              setState(() {
                _isLoading = true;
                _errorMessage = null;
              });
              _initialize();
            },
            style: ElevatedButton.styleFrom(
              backgroundColor: const Color(0xFFFF6B9D),
            ),
            child: const Text('重试'),
          ),
        ],
      ),
    );
  }

  /// 主菜单
  Widget _buildMenu() {
    return Column(
      mainAxisSize: MainAxisSize.min,
      children: [
        // 标题
        const Text(
          'MyGO',
          style: TextStyle(
            color: Color(0xFFFF6B9D),
            fontSize: 48,
            fontWeight: FontWeight.bold,
            letterSpacing: 4,
          ),
        ),
        const SizedBox(height: 8),
        const Text(
          '',
          style: TextStyle(
            color: Colors.white70,
            fontSize: 20,
            letterSpacing: 6,
          ),
        ),
        const SizedBox(height: 12),
        Container(
          padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 4),
          decoration: BoxDecoration(
            color: Colors.amber.withOpacity(0.1),
            borderRadius: BorderRadius.circular(12),
            border: Border.all(color: Colors.amber.withOpacity(0.2)),
          ),
          child: const Text(
            'version 1.0.0',
            style: TextStyle(color: Colors.amber, fontSize: 12),
          ),
        ),

        const SizedBox(height: 60),

        // 继续游戏按钮
        if (_hasSaveData) ...[
          _buildMenuButton(
            label: '继续游戏',
            onTap: _continueGame,
            primary: true,
          ),
          const SizedBox(height: 16),
        ],

        // 重新开始按钮
        _buildMenuButton(
          label: '重新开始',
          onTap: _startNewGame,
          primary: !_hasSaveData,
        ),
        const SizedBox(height: 16),

        // 查看流程图按钮
        _buildMenuButton(
          label: '剧情流程图',
          onTap: _openFlowMap,
          primary: false,
        ),

        // 结局收集按钮
        if (_endingsCount > 0)
          Padding(
            padding: const EdgeInsets.only(top: 24),
            child: _buildEndingsProgress(),
          ),
      ],
    );
  }

  /// 结局收集进度
  int _endingsCount = 0;

  Widget _buildEndingsProgress() {
    return Container(
      padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 8),
      decoration: BoxDecoration(
        color: Colors.amber.withOpacity(0.08),
        borderRadius: BorderRadius.circular(12),
        border: Border.all(color: Colors.amber.withOpacity(0.15)),
      ),
      child: Column(
        children: [
          const Text(
            '🏆 结局收集',
            style: TextStyle(
              color: Colors.amber,
              fontSize: 13,
              fontWeight: FontWeight.bold,
            ),
          ),
          const SizedBox(height: 6),
          Text(
            '已解锁 $_endingsCount / ${_engine.endingsMeta.length} 个结局',
            style: const TextStyle(color: Colors.white60, fontSize: 12),
          ),
        ],
      ),
    );
  }

  /// 打开流程图页面
  void _openFlowMap() {
    Navigator.of(context).push(
      MaterialPageRoute(
        builder: (_) => ChangeNotifierProvider.value(
          value: _engine,
          child: const FlowMapPage(),
        ),
      ),
    );
  }

  Widget _buildMenuButton({
    required String label,
    required VoidCallback onTap,
    required bool primary,
  }) {
    return GestureDetector(
      onTap: onTap,
      child: Container(
        width: 260,
        padding: const EdgeInsets.symmetric(vertical: 16),
        decoration: BoxDecoration(
          gradient: primary
              ? const LinearGradient(
                  colors: [Color(0xFFFF6B9D), Color(0xFFFF8A65)],
                )
              : LinearGradient(
                  colors: [
                    Colors.white.withOpacity(0.1),
                    Colors.white.withOpacity(0.05),
                  ],
                ),
          borderRadius: BorderRadius.circular(16),
          border: Border.all(
            color: primary ? Colors.transparent : Colors.white.withOpacity(0.2),
          ),
          boxShadow: primary
              ? [
                  BoxShadow(
                    color: const Color(0xFFFF6B9D).withOpacity(0.3),
                    blurRadius: 12,
                    spreadRadius: 1,
                  ),
                ]
              : null,
        ),
        child: Center(
          child: Text(
            label,
            style: const TextStyle(
              color: Colors.white,
              fontSize: 18,
              fontWeight: FontWeight.w600,
              letterSpacing: 2,
            ),
          ),
        ),
      ),
    );
  }
}

// ==================== 氛围粒子绘制器 ====================

/// 在主页无背景图时，绘制浮动光点营造氛围
class _ParticlePainter extends CustomPainter {
  // 伪随机粒子位置（固定种子确保视觉效果一致）
  static final List<_Particle> _particles = List.generate(30, (i) {
    final seed = i * 137.508;
    return _Particle(
      x: ((seed * 1.3) % 1.0),
      y: ((seed * 2.7 + 0.3) % 1.0),
      size: 1.5 + ((seed * 0.7) % 3.0),
      opacity: 0.1 + ((seed * 0.3) % 0.25),
    );
  });

  @override
  void paint(Canvas canvas, Size size) {
    for (final p in _particles) {
      final paint = Paint()
        ..color = const Color(0xFFFF6B9D).withOpacity(p.opacity)
        ..maskFilter = const MaskFilter.blur(BlurStyle.normal, 3);
      canvas.drawCircle(
        Offset(p.x * size.width, p.y * size.height),
        p.size,
        paint,
      );
    }
  }

  @override
  bool shouldRepaint(covariant CustomPainter oldDelegate) => false;
}

/// 粒子数据
class _Particle {
  final double x;
  final double y;
  final double size;
  final double opacity;
  const _Particle({
    required this.x,
    required this.y,
    required this.size,
    required this.opacity,
  });
}
