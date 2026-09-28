import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import '../engines/story_engine.dart';
import '../engines/save_manager.dart';
import '../models/story_node.dart';
import '../models/choice.dart';
import '../widgets/dialogue_box.dart';
import '../widgets/choice_button.dart';
import '../widgets/end_dialog.dart';
import '../widgets/background_view.dart';
import 'flow_map_page.dart';

/// 主剧情页面
/// 视觉小说核心界面，包含背景、对话、选项、过渡动画等
class StoryPage extends StatefulWidget {
  const StoryPage({super.key});

  @override
  State<StoryPage> createState() => _StoryPageState();
}

class _StoryPageState extends State<StoryPage> with TickerProviderStateMixin {
  /// 淡入淡出动画控制器
  late AnimationController _fadeController;
  late Animation<double> _fadeAnimation;

  /// 是否正在过渡中
  bool _isTransitioning = false;

  /// 选项按钮是否禁用
  bool _choicesLocked = false;

  /// 存档管理器
  final SaveManager _saveManager = SaveManager();

  /// 背景 key（用于触发过渡动画）
  Key _backgroundKey = UniqueKey();

  /// 存档状态提示
  String? _saveStatusText;
  bool _isSaving = false;

  @override
  void initState() {
    super.initState();
    _fadeController = AnimationController(
      vsync: this,
      duration: const Duration(milliseconds: 300),
    );
    _fadeAnimation = CurvedAnimation(
      parent: _fadeController,
      curve: Curves.easeInOut,
    );

    WidgetsBinding.instance.addPostFrameCallback((_) {
      _fadeController.forward();
    });
  }

  @override
  void dispose() {
    _fadeController.dispose();
    super.dispose();
  }

  /// 节点切换：淡出 -> 切换 -> 淡入
  Future<void> _transitionToNode(String nodeId) async {
    if (_isTransitioning) return;
    setState(() => _isTransitioning = true);

    // 淡出
    await _fadeController.reverse();

    // 获取引擎并跳转
    final engine = context.read<StoryEngine>();
    final target = engine.navigateTo(nodeId);

    if (target == null) {
      setState(() => _isTransitioning = false);
      return;
    }

    // 更新背景 key 以触发过渡
    _backgroundKey = UniqueKey();

    // 检查是否为结局
    if (target.type == NodeType.ending) {
      engine.handleEndingReached();
      await _saveManager.saveGame(engine.gameState);
      Future.delayed(const Duration(milliseconds: 800), () {
        _showEndingDialog(target);
      });
    } else {
      await _saveManager.saveGame(engine.gameState);
    }

    // 淡入
    await _fadeController.forward();
    setState(() => _isTransitioning = false);
  }

  /// 显示结局解锁弹窗
  void _showEndingDialog(StoryNode node) {
    if (!mounted) return;
    final engine = context.read<StoryEngine>();
    showDialog(
      context: context,
      barrierDismissible: false,
      builder: (_) => EndingDialog(
        endingName: node.endingName ?? '结局 ${node.endingId}',
        endingId: node.endingId ?? 0,
        stars: engine.getEndingStars(node.endingId ?? 1),
        onDismiss: () {
          Navigator.of(context).pop();
        },
        onRestart: () {
          Navigator.of(context).pop();
          _restartGame();
        },
      ),
    );
  }

  /// 重新开始游戏
  Future<void> _restartGame() async {
    final engine = context.read<StoryEngine>();
    engine.restartGame();
    await _saveManager.clearSave();
    _backgroundKey = UniqueKey();
    await _fadeController.forward();
    setState(() {
      _isTransitioning = false;
      _choicesLocked = false;
    });
  }

  /// 手动保存游戏
  Future<void> _manualSave() async {
    if (_isSaving) return;
    setState(() {
      _isSaving = true;
      _saveStatusText = '💾 正在存档…';
    });

    final engine = context.read<StoryEngine>();
    final success = await _saveManager.saveGame(engine.gameState);

    if (!mounted) return;
    setState(() {
      _isSaving = false;
      _saveStatusText = success ? '💾 已存档！' : '💾 存档失败';
    });

    // 2 秒后清除提示
    Future.delayed(const Duration(seconds: 2), () {
      if (mounted) {
        setState(() => _saveStatusText = null);
      }
    });
  }

  /// 返回上一节点
  Future<void> _goBack() async {
    final engine = context.read<StoryEngine>();
    if (!engine.canGoBack) return;
    if (_isTransitioning) return;

    setState(() => _isTransitioning = true);

    await _fadeController.reverse();
    engine.goBack();
    _backgroundKey = UniqueKey();
    await _fadeController.forward();

    setState(() => _isTransitioning = false);
  }

  /// 返回主页 — 弹出确认对话框后回到主菜单
  Future<void> _goHome() async {
    if (_isTransitioning) return;

    final confirmed = await showDialog<bool>(
      context: context,
      builder: (ctx) => AlertDialog(
        backgroundColor: const Color(0xFF1A1A2E),
        shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(16)),
        title: const Text('返回主页？', style: TextStyle(color: Colors.white)),
        content: const Text(
          '当前进度将自动保存，下次可继续游戏。',
          style: TextStyle(color: Colors.white70),
        ),
        actions: [
          TextButton(
            onPressed: () => Navigator.of(ctx).pop(false),
            child: const Text('取消', style: TextStyle(color: Colors.white54)),
          ),
          TextButton(
            onPressed: () => Navigator.of(ctx).pop(true),
            child: const Text(
              '返回主页',
              style: TextStyle(color: Color(0xFFFF6B9D)),
            ),
          ),
        ],
      ),
    );

    if (confirmed == true && mounted) {
      // 先自动存档
      final engine = context.read<StoryEngine>();
      await _saveManager.saveGame(engine.gameState);

      if (!mounted) return;
      // 弹出所有页面（流程图页/故事页），回到最底层的启动页
      // 启动页的 _enterGame().then() 会自动刷新存档与结局状态
      Navigator.of(context).popUntil((route) => route.isFirst);
    }
  }

  /// 处理对话节点的"继续"操作
  Future<void> _onContinue() async {
    final engine = context.read<StoryEngine>();
    if (engine.isCurrentNodeEnding) return;
    final nextId = engine.currentNode?.next;
    if (nextId != null) {
      await _transitionToNode(nextId);
    }
  }

  /// 处理选项选择
  Future<void> _onChoiceSelected(Choice choice) async {
    setState(() => _choicesLocked = true);
    await _transitionToNode(choice.nextNode);
    await Future.delayed(const Duration(milliseconds: 600));
    if (mounted) {
      setState(() => _choicesLocked = false);
    }
  }

  /// 打开流程图页面
  void _openFlowMap() {
    Navigator.of(
      context,
    ).push(MaterialPageRoute(builder: (_) => const FlowMapPage()));
  }

  @override
  Widget build(BuildContext context) {
    return Consumer<StoryEngine>(
      builder: (context, engine, _) {
        final node = engine.currentNode;

        return Scaffold(
          body: Stack(
            children: [
              // ===== 背景图层（带过渡动画） =====
              Positioned.fill(
                child: BackgroundView(
                  key: _backgroundKey,
                  backgroundImage: node?.background,
                  enableBlur: node?.type == NodeType.ending,
                  blurStrength: 3.0,
                  overlayOpacity: 0.35,
                ),
              ),

              // ===== 主内容区 =====
              SafeArea(
                child: Column(
                  children: [
                    // ===== 顶部：操作栏 =====
                    _buildTopBar(engine),

                    // ===== 中部：核心展示区 =====
                    Expanded(flex: 7, child: _buildCenterArea(node, engine)),

                    // ===== 底部：对话框 / 选项按钮区域 =====
                    _buildBottomArea(node, engine),
                  ],
                ),
              ),
            ],
          ),
        );
      },
    );
  }

  /// 构建顶部栏
  Widget _buildTopBar(StoryEngine engine) {
    final node = engine.currentNode;

    return Container(
      padding: const EdgeInsets.symmetric(horizontal: 12, vertical: 8),
      decoration: BoxDecoration(
        gradient: LinearGradient(
          colors: [
            Colors.black.withOpacity(0.6),
            Colors.black.withOpacity(0.2),
          ],
          begin: Alignment.topCenter,
          end: Alignment.bottomCenter,
        ),
      ),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          // 左侧：返回 + 标题
          Row(
            children: [
              // 返回按钮
              if (engine.canGoBack && node?.type != NodeType.ending)
                GestureDetector(
                  onTap: _goBack,
                  child: Container(
                    padding: const EdgeInsets.all(8),
                    margin: const EdgeInsets.only(right: 4),
                    decoration: BoxDecoration(
                      color: Colors.white.withOpacity(0.1),
                      borderRadius: BorderRadius.circular(10),
                    ),
                    child: const Icon(
                      Icons.undo,
                      color: Colors.white70,
                      size: 20,
                    ),
                  ),
                ),
              const Text(
                'MyGO',
                style: TextStyle(
                  color: Colors.white,
                  fontSize: 18,
                  fontWeight: FontWeight.bold,
                  letterSpacing: 1,
                ),
              ),
              const SizedBox(width: 4),
              // 返回主页按钮
              GestureDetector(
                onTap: _goHome,
                child: Container(
                  padding: const EdgeInsets.all(6),
                  decoration: BoxDecoration(
                    color: Colors.white.withOpacity(0.1),
                    borderRadius: BorderRadius.circular(8),
                  ),
                  child: const Icon(
                    Icons.home_outlined,
                    color: Colors.white70,
                    size: 18,
                  ),
                ),
              ),
              const SizedBox(width: 4),
              // 流程图按钮
              GestureDetector(
                onTap: _openFlowMap,
                child: Container(
                  padding: const EdgeInsets.all(6),
                  decoration: BoxDecoration(
                    color: Colors.white.withOpacity(0.1),
                    borderRadius: BorderRadius.circular(8),
                  ),
                  child: const Icon(
                    Icons.account_tree_outlined,
                    color: Colors.white70,
                    size: 18,
                  ),
                ),
              ),
            ],
          ),

          // 右侧：保存 + 重新开始 + 进度
          Row(
            mainAxisSize: MainAxisSize.min,
            children: [
              // 手动存档按钮
              if (node?.type != NodeType.ending &&
                  node?.type != NodeType.choice)
                GestureDetector(
                  onTap: _manualSave,
                  child: Container(
                    padding: const EdgeInsets.all(6),
                    decoration: BoxDecoration(
                      color: Colors.white.withOpacity(0.1),
                      borderRadius: BorderRadius.circular(8),
                    ),
                    child: Icon(
                      _isSaving ? Icons.hourglass_top : Icons.save_outlined,
                      color: _saveStatusText != null
                          ? Colors.green
                          : Colors.white70,
                      size: 18,
                    ),
                  ),
                ),
              const SizedBox(width: 6),
              // 重新开始
              GestureDetector(
                onTap: () => _showRestartConfirm(),
                child: Container(
                  padding: const EdgeInsets.all(6),
                  decoration: BoxDecoration(
                    color: Colors.white.withOpacity(0.1),
                    borderRadius: BorderRadius.circular(8),
                  ),
                  child: const Icon(
                    Icons.refresh,
                    color: Colors.white70,
                    size: 18,
                  ),
                ),
              ),
              const SizedBox(width: 8),
              // 进度百分比
              Container(
                padding: const EdgeInsets.symmetric(
                  horizontal: 10,
                  vertical: 4,
                ),
                decoration: BoxDecoration(
                  color: Colors.white.withOpacity(0.1),
                  borderRadius: BorderRadius.circular(12),
                ),
                child: Text(
                  '${(engine.progress * 100).toStringAsFixed(0)}%',
                  style: const TextStyle(
                    color: Colors.amber,
                    fontSize: 13,
                    fontWeight: FontWeight.bold,
                  ),
                ),
              ),
            ],
          ),
        ],
      ),
    );
  }

  /// 构建中间区域（剧情文本 + 提问）
  Widget _buildCenterArea(StoryNode? node, StoryEngine engine) {
    if (node == null) return const SizedBox.shrink();

    return Column(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        // 选项节点：显示提问文字
        if (node.type == NodeType.choice)
          Padding(
            padding: const EdgeInsets.symmetric(horizontal: 32),
            child: FadeTransition(
              opacity: _fadeAnimation,
              child: Column(
                children: [
                  // 剧情文本（选项节点上方的描述）
                  if (node.text.isNotEmpty)
                    Container(
                      padding: const EdgeInsets.all(20),
                      decoration: BoxDecoration(
                        color: Colors.black.withOpacity(0.5),
                        borderRadius: BorderRadius.circular(16),
                        border: Border.all(
                          color: Colors.white.withOpacity(0.1),
                        ),
                      ),
                      child: Text(
                        node.text,
                        style: const TextStyle(
                          color: Colors.white,
                          fontSize: 20,
                          height: 1.6,
                          letterSpacing: 1,
                        ),
                        textAlign: TextAlign.center,
                      ),
                    ),
                  const SizedBox(height: 24),
                  // 提问文字
                  if (node.question != null)
                    Container(
                      padding: const EdgeInsets.symmetric(
                        horizontal: 24,
                        vertical: 12,
                      ),
                      decoration: BoxDecoration(
                        color: Colors.amber.withOpacity(0.15),
                        borderRadius: BorderRadius.circular(12),
                        border: Border.all(
                          color: Colors.amber.withOpacity(0.3),
                        ),
                      ),
                      child: Text(
                        node.question!,
                        style: const TextStyle(
                          color: Colors.amberAccent,
                          fontSize: 22,
                          fontWeight: FontWeight.bold,
                          letterSpacing: 2,
                        ),
                        textAlign: TextAlign.center,
                      ),
                    ),
                ],
              ),
            ),
          ),

        // 存档状态提示
        if (_saveStatusText != null)
          Padding(
            padding: const EdgeInsets.only(top: 16),
            child: Text(
              _saveStatusText!,
              style: const TextStyle(
                color: Colors.greenAccent,
                fontSize: 14,
                fontWeight: FontWeight.w500,
              ),
            ),
          ),
      ],
    );
  }

  /// 构建底部区域（对话框 + 选项按钮）
  Widget _buildBottomArea(StoryNode? node, StoryEngine engine) {
    if (node == null) return const SizedBox.shrink();

    return Container(
      padding: const EdgeInsets.only(bottom: 16),
      child: Column(
        mainAxisSize: MainAxisSize.min,
        children: [
          // 对话/结局节点：显示对话框
          if (node.type == NodeType.dialogue || node.type == NodeType.ending)
            FadeTransition(
              opacity: _fadeAnimation,
              child: DialogueBox(
                node: node,
                isTransitioning: _isTransitioning,
                onTypewriterComplete: () {},
                onTap: node.type == NodeType.dialogue ? _onContinue : null,
              ),
            ),

          // 选项节点：显示选择按钮
          if (node.type == NodeType.choice && node.choices != null)
            FadeTransition(
              opacity: _fadeAnimation,
              child: Padding(
                padding: const EdgeInsets.symmetric(horizontal: 32),
                child: Column(
                  children: node.choices!.map((choice) {
                    return Padding(
                      padding: const EdgeInsets.only(bottom: 12),
                      child: ChoiceButton(
                        text: choice.text,
                        isDisabled: _choicesLocked || _isTransitioning,
                        onTap: () => _onChoiceSelected(choice),
                      ),
                    );
                  }).toList(),
                ),
              ),
            ),
        ],
      ),
    );
  }

  /// 显示重新开始确认对话框
  void _showRestartConfirm() {
    showDialog(
      context: context,
      builder: (ctx) => AlertDialog(
        backgroundColor: const Color(0xFF1A1A2E),
        shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(16)),
        title: const Text('重新开始？', style: TextStyle(color: Colors.white)),
        content: const Text(
          '当前进度将丢失，确定要重新开始吗？',
          style: TextStyle(color: Colors.white70),
        ),
        actions: [
          TextButton(
            onPressed: () => Navigator.of(ctx).pop(),
            child: const Text('取消', style: TextStyle(color: Colors.white54)),
          ),
          TextButton(
            onPressed: () {
              Navigator.of(ctx).pop();
              _restartGame();
            },
            child: const Text('确定', style: TextStyle(color: Color(0xFFFF6B9D))),
          ),
        ],
      ),
    );
  }
}
