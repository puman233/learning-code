import 'dart:math' as math;
import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import '../engines/story_engine.dart';
import '../models/story_node.dart';
import '../models/choice.dart';
import '../services/character_service.dart';

/// 动态流程图地图页面
/// 使用 InteractiveViewer 实现缩放与拖拽
/// CustomPaint 绘制节点之间的贝塞尔曲线连线，支持分支标签
class FlowMapPage extends StatefulWidget {
  const FlowMapPage({super.key});

  @override
  State<FlowMapPage> createState() => _FlowMapPageState();
}

class _FlowMapPageState extends State<FlowMapPage>
    with SingleTickerProviderStateMixin {
  /// 缩放控制器引用
  final TransformationController _transformController =
      TransformationController();

  /// 动画控制器用于跳动定位
  late AnimationController _animController;

  /// 统计信息缓存
  int _dialogueCount = 0;
  int _choiceCount = 0;
  int _endingCount = 0;

  @override
  void initState() {
    super.initState();
    _animController = AnimationController(
      vsync: this,
      duration: const Duration(milliseconds: 600),
    );
  }

  @override
  void dispose() {
    _animController.dispose();
    _transformController.dispose();
    super.dispose();
  }

  /// 节点类型过滤状态
  bool _showDialogue = true;
  bool _showChoice = true;
  bool _showEnding = true;

  /// 当前缩放比例
  double _currentScale = 1.0;

  /// 搜索关键词
  String _searchQuery = '';

  /// 是否显示搜索栏
  bool _showSearch = false;

  /// 搜索控制器
  final TextEditingController _searchController = TextEditingController();

  /// 是否显示结局面板
  bool _showEndingsPanel = false;

  /// 平滑滚动到指定坐标
  void _animateScrollTo(double x, double y) {
    // 快速直接跳转（避免复杂矩阵动画的抖动）
    final targetMatrix = Matrix4.identity()..translate(-(x - 400), -(y - 300));
    _transformController.value = targetMatrix;
  }

  /// 平移到当前节点位置
  void _scrollToCurrent(StoryEngine engine) {
    final node = engine.currentNode;
    if (node == null) return;
    _animateScrollTo(node.x, node.y);
  }

  /// 平移到指定节点
  void _scrollToNode(StoryNode targetNode) {
    _animateScrollTo(targetNode.x, targetNode.y);
  }

  /// 搜索并跳转到匹配的第一个节点
  void _searchAndScroll(List<StoryNode> nodes) {
    if (_searchQuery.trim().isEmpty) return;
    final q = _searchQuery.toLowerCase().trim();
    final match = nodes.cast<StoryNode?>().firstWhere(
          (n) =>
              n!.id.toLowerCase().contains(q) ||
              n.text.toLowerCase().contains(q) ||
              n.speaker.toLowerCase().contains(q) ||
              (n.question?.toLowerCase().contains(q) ?? false),
          orElse: () => null,
        );
    if (match != null) {
      _animateScrollTo(match.x, match.y);
      _showNodeDetail(match);
    }
  }

  /// 过滤节点（类型 + 搜索关键词）
  List<StoryNode> _filterNodes(List<StoryNode> nodes) {
    var filtered = nodes.where((n) {
      switch (n.type) {
        case NodeType.dialogue:
          return _showDialogue;
        case NodeType.choice:
          return _showChoice;
        case NodeType.ending:
          return _showEnding;
      }
    });

    // 搜索关键词过滤
    if (_searchQuery.trim().isNotEmpty) {
      final q = _searchQuery.toLowerCase().trim();
      filtered = filtered.where(
        (n) =>
            n.id.toLowerCase().contains(q) ||
            n.text.toLowerCase().contains(q) ||
            n.speaker.toLowerCase().contains(q) ||
            (n.question?.toLowerCase().contains(q) ?? false) ||
            (n.endingName?.toLowerCase().contains(q) ?? false),
      );
    }

    return filtered.toList();
  }

  /// 显示节点详情弹窗
  void _showNodeDetail(StoryNode node, {StoryEngine? engine}) {
    final charService = CharacterService();
    final endingStars = (node.endingId != null && engine != null)
        ? engine.getEndingStars(node.endingId!)
        : 0;
    final character = node.characterId != null
        ? charService.getCharacter(node.characterId!)
        : charService.findByName(node.speaker);

    final Color nodeColor = _getNodeColor(node);
    final String typeLabel = _getNodeTypeLabel(node);

    showDialog(
      context: context,
      builder: (ctx) => Dialog(
        backgroundColor: Colors.transparent,
        child: Container(
          padding: const EdgeInsets.all(24),
          decoration: BoxDecoration(
            gradient: LinearGradient(
              colors: [
                const Color(0xFF1A1A2E).withOpacity(0.97),
                const Color(0xFF16213E).withOpacity(0.97),
              ],
              begin: Alignment.topLeft,
              end: Alignment.bottomRight,
            ),
            borderRadius: BorderRadius.circular(20),
            border: Border.all(color: nodeColor.withOpacity(0.4), width: 1.5),
          ),
          child: Column(
            mainAxisSize: MainAxisSize.min,
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              // 标题行：节点 ID + 类型标签
              Row(
                children: [
                  Container(
                    padding:
                        const EdgeInsets.symmetric(horizontal: 10, vertical: 4),
                    decoration: BoxDecoration(
                      color: nodeColor.withOpacity(0.2),
                      borderRadius: BorderRadius.circular(8),
                      border: Border.all(color: nodeColor.withOpacity(0.3)),
                    ),
                    child: Text(
                      typeLabel,
                      style: TextStyle(
                        color: nodeColor,
                        fontSize: 12,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ),
                  const SizedBox(width: 8),
                  Text(
                    node.id,
                    style: const TextStyle(
                      color: Colors.white54,
                      fontSize: 11,
                      fontFamily: 'monospace',
                    ),
                  ),
                ],
              ),
              const SizedBox(height: 16),

              // 角色信息
              if (character != null &&
                  node.speaker != '系统' &&
                  node.speaker != '旁白') ...[
                Row(
                  children: [
                    // 小头像
                    Container(
                      width: 40,
                      height: 40,
                      decoration: BoxDecoration(
                        shape: BoxShape.circle,
                        color: nodeColor.withOpacity(0.15),
                        border: Border.all(color: nodeColor.withOpacity(0.4)),
                      ),
                      child: ClipOval(
                        child: Image.asset(
                          character.avatarAssetPath,
                          fit: BoxFit.cover,
                          errorBuilder: (_, __, ___) => Center(
                            child: Text(
                              character.name[0],
                              style: TextStyle(
                                color: nodeColor,
                                fontSize: 18,
                                fontWeight: FontWeight.bold,
                              ),
                            ),
                          ),
                        ),
                      ),
                    ),
                    const SizedBox(width: 12),
                    Text(
                      node.speaker,
                      style: TextStyle(
                        color: nodeColor,
                        fontSize: 18,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ],
                ),
                const SizedBox(height: 12),
              ],

              // 文本内容
              Container(
                width: double.infinity,
                padding: const EdgeInsets.all(14),
                decoration: BoxDecoration(
                  color: Colors.white.withOpacity(0.05),
                  borderRadius: BorderRadius.circular(12),
                ),
                child: Text(
                  node.text.replaceAll('\n', ' '),
                  style: const TextStyle(
                    color: Colors.white,
                    fontSize: 15,
                    height: 1.5,
                  ),
                ),
              ),

              // 选项节点：显示分支选项
              if (node.type == NodeType.choice && node.choices != null) ...[
                const SizedBox(height: 12),
                const Text(
                  '📌 分支选项：',
                  style: TextStyle(
                    color: Colors.amberAccent,
                    fontSize: 13,
                    fontWeight: FontWeight.bold,
                  ),
                ),
                const SizedBox(height: 8),
                ...node.choices!.asMap().entries.map((entry) {
                  final idx = entry.key;
                  final choice = entry.value;
                  final branchColor = [
                    Colors.greenAccent,
                    Colors.orangeAccent,
                    Colors.blueAccent,
                    Colors.pinkAccent,
                  ][idx % 4];
                  return Padding(
                    padding: const EdgeInsets.only(bottom: 6),
                    child: Row(
                      children: [
                        Container(
                          width: 6,
                          height: 6,
                          margin: const EdgeInsets.only(right: 8),
                          decoration: BoxDecoration(
                            shape: BoxShape.circle,
                            color: branchColor,
                          ),
                        ),
                        Expanded(
                          child: Text(
                            '「${choice.text}」 → ${choice.nextNode}',
                            style: const TextStyle(
                              color: Colors.white70,
                              fontSize: 13,
                            ),
                          ),
                        ),
                      ],
                    ),
                  );
                }),
              ],

              // 结局节点
              if (node.type == NodeType.ending) ...[
                const SizedBox(height: 12),
                if (node.endingName != null)
                  Container(
                    padding:
                        const EdgeInsets.symmetric(horizontal: 12, vertical: 6),
                    decoration: BoxDecoration(
                      gradient: LinearGradient(
                        colors: [
                          Colors.amber.withOpacity(0.15),
                          Colors.orange.withOpacity(0.1),
                        ],
                      ),
                      borderRadius: BorderRadius.circular(8),
                      border: Border.all(color: Colors.amber.withOpacity(0.3)),
                    ),
                    child: Column(
                      children: [
                        Row(
                          mainAxisSize: MainAxisSize.min,
                          children: [
                            const Text('🏆 ', style: TextStyle(fontSize: 16)),
                            Text(
                              node.endingName!,
                              style: const TextStyle(
                                color: Colors.amber,
                                fontSize: 14,
                                fontWeight: FontWeight.bold,
                              ),
                            ),
                          ],
                        ),
                        if (node.endingId != null && endingStars > 0) ...[
                          const SizedBox(height: 4),
                          Row(
                            mainAxisSize: MainAxisSize.min,
                            children: List.generate(5, (i) {
                              return Icon(
                                i < endingStars
                                    ? Icons.star
                                    : Icons.star_border,
                                color: Colors.amber,
                                size: 16,
                              );
                            }),
                          ),
                        ],
                      ],
                    ),
                  ),
              ],

              const SizedBox(height: 16),
              // 坐标信息
              Text(
                '位置: (${node.x.toInt()}, ${node.y.toInt()})',
                style: const TextStyle(color: Colors.white30, fontSize: 10),
              ),
              const SizedBox(height: 12),
              // 操作按钮
              Row(
                mainAxisAlignment: MainAxisAlignment.end,
                children: [
                  GestureDetector(
                    onTap: () {
                      Navigator.of(ctx).pop();
                      // 延迟后平移到该节点（等弹窗关闭后）
                      Future.delayed(const Duration(milliseconds: 200), () {
                        _scrollToNode(node);
                      });
                    },
                    child: Container(
                      padding: const EdgeInsets.symmetric(
                          horizontal: 14, vertical: 8),
                      decoration: BoxDecoration(
                        gradient: LinearGradient(
                          colors: [
                            nodeColor.withOpacity(0.3),
                            nodeColor.withOpacity(0.1),
                          ],
                        ),
                        borderRadius: BorderRadius.circular(10),
                        border: Border.all(color: nodeColor.withOpacity(0.4)),
                      ),
                      child: const Text(
                        '📍 定位到此',
                        style: TextStyle(
                          color: Colors.white,
                          fontSize: 13,
                          fontWeight: FontWeight.w500,
                        ),
                      ),
                    ),
                  ),
                ],
              ),
            ],
          ),
        ),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: const Color(0xFF0D0221),
      appBar: AppBar(
        title: const Text('剧情流程图', style: TextStyle(color: Colors.white)),
        backgroundColor: const Color(0xFF1A0A3E),
        iconTheme: const IconThemeData(color: Colors.white),
        elevation: 0,
        actions: [
          // 搜索按钮
          IconButton(
            icon: Icon(
              _showSearch ? Icons.search_off : Icons.search,
              color: Colors.white70,
            ),
            onPressed: () => setState(() => _showSearch = !_showSearch),
          ),
          // 结局面板按钮
          IconButton(
            icon: const Icon(Icons.emoji_events_outlined,
                color: Colors.amberAccent),
            onPressed: () => _showEndingsSheet(context),
          ),
          // 图例
          Padding(
            padding: const EdgeInsets.only(right: 4),
            child: Row(
              mainAxisSize: MainAxisSize.min,
              children: [
                _buildLegendItem(Colors.amber, '当前'),
                const SizedBox(width: 6),
                _buildLegendItem(const Color(0xFF4CAF50), '已读'),
                const SizedBox(width: 6),
                _buildLegendItem(Colors.grey, '未读'),
                const SizedBox(width: 6),
                _buildLegendItem(const Color(0xFFE74C3C), '结局'),
              ],
            ),
          ),
        ],
      ),
      body: Consumer<StoryEngine>(
        builder: (context, engine, _) {
          final allNodes = engine.allNodes;
          final visitedIds = engine.gameState.visitedNodeIds;
          final currentNodeId = engine.gameState.currentNodeId;
          final connections = engine.getConnections();

          // 应用类型过滤
          final nodes = _filterNodes(allNodes);
          final allChoices = _buildChoiceLabelMap(nodes);

          // 统计
          _dialogueCount =
              allNodes.where((n) => n.type == NodeType.dialogue).length;
          _choiceCount =
              allNodes.where((n) => n.type == NodeType.choice).length;
          _endingCount =
              allNodes.where((n) => n.type == NodeType.ending).length;

          return Column(
            children: [
              // ===== 搜索栏（展开/收起） =====
              if (_showSearch) _buildSearchBar(),

              // ===== 过滤工具栏 =====
              _buildFilterBar(),

              // ===== 流程图主体 =====
              Expanded(
                child: Stack(
                  children: [
                    InteractiveViewer(
                      transformationController: _transformController,
                      minScale: 0.3,
                      maxScale: 3.0,
                      boundaryMargin: const EdgeInsets.all(200),
                      onInteractionEnd: (details) {
                        // 更新当前缩放比例
                        setState(() {
                          _currentScale =
                              _transformController.value.getMaxScaleOnAxis();
                        });
                      },
                      child: SizedBox(
                        width: _calculateCanvasWidth(allNodes),
                        height: _calculateCanvasHeight(allNodes),
                        child: Stack(
                          children: [
                            // 贝塞尔曲线连线（含分支标签）
                            CustomPaint(
                              size: Size(
                                _calculateCanvasWidth(allNodes),
                                _calculateCanvasHeight(allNodes),
                              ),
                              painter: _ConnectionPainter(
                                connections: connections,
                                nodes: allNodes,
                                visitedIds: visitedIds,
                                choiceLabels: allChoices,
                              ),
                            ),
                            // 分支标签（文字浮层）
                            ..._buildBranchLabels(
                                connections, allNodes, allChoices),
                            // 节点圆点
                            ...nodes.map(
                              (node) => _buildNodeDot(
                                node: node,
                                isVisited: visitedIds.contains(node.id),
                                isCurrent: node.id == currentNodeId,
                                onTap: () =>
                                    _showNodeDetail(node, engine: engine),
                              ),
                            ),
                          ],
                        ),
                      ),
                    ),

                    // 缩放比例指示器
                    Positioned(
                      left: 12,
                      top: 12,
                      child: _buildScaleIndicator(),
                    ),

                    // 跳转到当前节点按钮
                    Positioned(
                      right: 16,
                      bottom: 16,
                      child: FloatingActionButton.small(
                        heroTag: 'scroll_to_current',
                        backgroundColor: const Color(0xFFFF6B9D),
                        onPressed: () => _scrollToCurrent(engine),
                        child:
                            const Icon(Icons.my_location, color: Colors.white),
                      ),
                    ),

                    // 底部统计栏（覆盖在流程图之上）
                    Positioned(
                      left: 0,
                      right: 0,
                      bottom: 0,
                      child: _buildStatsBar(engine),
                    ),
                  ],
                ),
              ),
            ],
          );
        },
      ),
    );
  }

  /// 构建节点之间的分支标签
  List<Widget> _buildBranchLabels(
    List<List<String>> connections,
    List<StoryNode> nodes,
    Map<String, String> choiceLabels,
  ) {
    final nodeMap = <String, StoryNode>{};
    for (final node in nodes) {
      nodeMap[node.id] = node;
    }

    final labels = <Widget>[];
    final labelPositions = <String, int>{};

    for (final conn in connections) {
      final from = nodeMap[conn[0]];
      final to = nodeMap[conn[1]];
      if (from == null || to == null) continue;

      // 查找该连线对应的选择文本
      final connKey = '${conn[0]}->${conn[1]}';
      final label = choiceLabels[connKey];

      if (label != null && label.isNotEmpty) {
        // 计算标签位置（连线中点偏上）
        final midX = (from.x + to.x) / 2;
        final midY = (from.y + to.y) / 2;

        // 避免标签重叠
        final posKey = '${midX.toInt()},${midY.toInt()}';
        final offset = (labelPositions[posKey] ?? 0) * 14;
        labelPositions[posKey] = (labelPositions[posKey] ?? 0) + 1;

        labels.add(
          Positioned(
            left: midX - 60,
            top: midY - 22 + offset,
            child: Container(
              padding: const EdgeInsets.symmetric(horizontal: 6, vertical: 2),
              decoration: BoxDecoration(
                color: Colors.black.withOpacity(0.75),
                borderRadius: BorderRadius.circular(6),
                border: Border.all(color: Colors.white.withOpacity(0.15)),
              ),
              child: Text(
                label,
                style: const TextStyle(
                  color: Colors.white,
                  fontSize: 9,
                  fontWeight: FontWeight.w500,
                ),
                textAlign: TextAlign.center,
                maxLines: 2,
                overflow: TextOverflow.ellipsis,
              ),
            ),
          ),
        );
      }
    }
    return labels;
  }

  /// 构建选择文本映射表
  Map<String, String> _buildChoiceLabelMap(List<StoryNode> nodes) {
    final map = <String, String>{};
    for (final node in nodes) {
      if (node.type == NodeType.choice && node.choices != null) {
        for (final choice in node.choices!) {
          final key = '${node.id}->${choice.nextNode}';
          final text = choice.text.length > 6
              ? '${choice.text.substring(0, 6)}…'
              : choice.text;
          map[key] = text;
        }
      }
    }
    return map;
  }

  /// 构建底部统计栏
  Widget _buildStatsBar(StoryEngine engine) {
    return Container(
      padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 10),
      decoration: BoxDecoration(
        gradient: LinearGradient(
          colors: [
            Colors.black.withOpacity(0.85),
            Colors.black.withOpacity(0.6),
          ],
          begin: Alignment.bottomCenter,
          end: Alignment.topCenter,
        ),
      ),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceEvenly,
        children: [
          _buildStatItem(Icons.chat_bubble_outline, '对话', _dialogueCount,
              const Color(0xFF4ECDC4)),
          _buildStatItem(
              Icons.alt_route, '分支', _choiceCount, const Color(0xFFFFA726)),
          _buildStatItem(
              Icons.flag_outlined, '结局', _endingCount, const Color(0xFFE74C3C)),
          Container(
            width: 1,
            height: 24,
            color: Colors.white.withOpacity(0.1),
          ),
          _buildStatItem(Icons.explore_outlined, '进度',
              engine.gameState.visitedNodeIds.length, const Color(0xFFFF6B9D),
              suffix: '/${engine.totalNodeCount}'),
        ],
      ),
    );
  }

  /// 构建搜索栏
  Widget _buildSearchBar() {
    return Container(
      padding: const EdgeInsets.symmetric(horizontal: 12, vertical: 6),
      color: const Color(0xFF1A0A3E).withOpacity(0.95),
      child: Row(
        children: [
          Expanded(
            child: TextField(
              controller: _searchController,
              style: const TextStyle(color: Colors.white, fontSize: 13),
              decoration: InputDecoration(
                hintText: '搜索节点ID、角色名、关键词…',
                hintStyle: const TextStyle(color: Colors.white30, fontSize: 12),
                prefixIcon:
                    const Icon(Icons.search, color: Colors.white38, size: 18),
                suffixIcon: _searchController.text.isNotEmpty
                    ? IconButton(
                        icon: const Icon(Icons.clear,
                            color: Colors.white38, size: 16),
                        onPressed: () {
                          _searchController.clear();
                          setState(() => _searchQuery = '');
                        },
                      )
                    : null,
                filled: true,
                fillColor: Colors.white.withOpacity(0.08),
                contentPadding:
                    const EdgeInsets.symmetric(horizontal: 12, vertical: 8),
                border: OutlineInputBorder(
                  borderRadius: BorderRadius.circular(10),
                  borderSide: BorderSide.none,
                ),
              ),
              onChanged: (v) => setState(() => _searchQuery = v),
              onSubmitted: (_) {
                // 搜索并跳转到结果
                if (context.read<StoryEngine>().allNodes.isNotEmpty) {
                  _searchAndScroll(context.read<StoryEngine>().allNodes);
                }
              },
            ),
          ),
          const SizedBox(width: 8),
          // 搜索并跳转按钮
          GestureDetector(
            onTap: () {
              if (context.read<StoryEngine>().allNodes.isNotEmpty) {
                _searchAndScroll(context.read<StoryEngine>().allNodes);
              }
            },
            child: Container(
              padding: const EdgeInsets.all(8),
              decoration: BoxDecoration(
                color: const Color(0xFFFF6B9D).withOpacity(0.2),
                borderRadius: BorderRadius.circular(8),
              ),
              child: const Icon(Icons.arrow_forward,
                  color: Colors.white70, size: 18),
            ),
          ),
        ],
      ),
    );
  }

  /// 显示结局面板（底部弹出）
  void _showEndingsSheet(BuildContext context) {
    final engine = context.read<StoryEngine>();
    final endingsMeta = engine.endingsMeta;
    final unlockedEndings = engine.gameState.unlockedEndings;

    showModalBottomSheet(
      context: context,
      backgroundColor: Colors.transparent,
      builder: (ctx) => Container(
        padding: const EdgeInsets.all(20),
        decoration: const BoxDecoration(
          color: Color(0xFF1A1A2E),
          borderRadius: BorderRadius.vertical(top: Radius.circular(24)),
        ),
        child: Column(
          mainAxisSize: MainAxisSize.min,
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            // 标题
            Row(
              children: [
                const Icon(Icons.emoji_events, color: Colors.amber, size: 22),
                const SizedBox(width: 8),
                const Text(
                  '结局收集',
                  style: TextStyle(
                    color: Colors.white,
                    fontSize: 18,
                    fontWeight: FontWeight.bold,
                  ),
                ),
                const Spacer(),
                Text(
                  '${unlockedEndings.length} / ${endingsMeta.length}',
                  style: TextStyle(
                    color: Colors.amber,
                    fontSize: 14,
                    fontWeight: FontWeight.bold,
                  ),
                ),
              ],
            ),
            const SizedBox(height: 4),
            const Text(
              '已解锁的结局将会永久记录',
              style: TextStyle(color: Colors.white38, fontSize: 11),
            ),
            const SizedBox(height: 16),
            // 结局列表
            ...endingsMeta.entries.map((entry) {
              final isUnlocked = unlockedEndings.contains(entry.key);
              final data = entry.value;
              final name = data['name'] as String? ?? '结局 ${entry.key}';
              final desc = data['description'] as String? ?? '';
              final stars = (data['stars'] as int?) ?? 0;

              return Container(
                margin: const EdgeInsets.only(bottom: 10),
                padding: const EdgeInsets.all(12),
                decoration: BoxDecoration(
                  color: isUnlocked
                      ? Colors.amber.withOpacity(0.08)
                      : Colors.white.withOpacity(0.03),
                  borderRadius: BorderRadius.circular(12),
                  border: Border.all(
                    color: isUnlocked
                        ? Colors.amber.withOpacity(0.3)
                        : Colors.white.withOpacity(0.06),
                  ),
                ),
                child: Row(
                  children: [
                    // 图标
                    Container(
                      width: 40,
                      height: 40,
                      decoration: BoxDecoration(
                        shape: BoxShape.circle,
                        color: isUnlocked
                            ? Colors.amber.withOpacity(0.15)
                            : Colors.white.withOpacity(0.05),
                      ),
                      child: Center(
                        child: Text(
                          isUnlocked ? '🏆' : '❓',
                          style: const TextStyle(fontSize: 20),
                        ),
                      ),
                    ),
                    const SizedBox(width: 12),
                    Expanded(
                      child: Column(
                        crossAxisAlignment: CrossAxisAlignment.start,
                        children: [
                          Text(
                            isUnlocked ? name : '???',
                            style: TextStyle(
                              color: isUnlocked ? Colors.white : Colors.white38,
                              fontSize: 14,
                              fontWeight: FontWeight.w600,
                            ),
                          ),
                          if (isUnlocked && desc.isNotEmpty) ...[
                            const SizedBox(height: 2),
                            Text(
                              desc,
                              style: const TextStyle(
                                color: Colors.white54,
                                fontSize: 11,
                              ),
                              maxLines: 2,
                              overflow: TextOverflow.ellipsis,
                            ),
                          ],
                          if (isUnlocked) ...[
                            const SizedBox(height: 4),
                            Row(
                              children: List.generate(5, (i) {
                                return Icon(
                                  i < stars ? Icons.star : Icons.star_border,
                                  color: Colors.amber,
                                  size: 12,
                                );
                              }),
                            ),
                          ],
                        ],
                      ),
                    ),
                    // 状态标记
                    if (isUnlocked)
                      Container(
                        padding: const EdgeInsets.symmetric(
                            horizontal: 6, vertical: 2),
                        decoration: BoxDecoration(
                          color: Colors.green.withOpacity(0.15),
                          borderRadius: BorderRadius.circular(6),
                        ),
                        child: const Text(
                          '已解锁',
                          style: TextStyle(
                            color: Colors.greenAccent,
                            fontSize: 10,
                          ),
                        ),
                      )
                    else
                      Container(
                        padding: const EdgeInsets.symmetric(
                            horizontal: 6, vertical: 2),
                        decoration: BoxDecoration(
                          color: Colors.white.withOpacity(0.05),
                          borderRadius: BorderRadius.circular(6),
                        ),
                        child: const Text(
                          '未解锁',
                          style: TextStyle(
                            color: Colors.white30,
                            fontSize: 10,
                          ),
                        ),
                      ),
                  ],
                ),
              );
            }),
          ],
        ),
      ),
    );
  }

  /// 构建类型过滤工具栏
  Widget _buildFilterBar() {
    return Container(
      padding: const EdgeInsets.symmetric(horizontal: 12, vertical: 6),
      decoration: BoxDecoration(
        color: const Color(0xFF1A0A3E).withOpacity(0.9),
        border: Border(
          bottom: BorderSide(color: Colors.white.withOpacity(0.05)),
        ),
      ),
      child: Row(
        children: [
          const Text(
            '筛选:',
            style: TextStyle(color: Colors.white54, fontSize: 12),
          ),
          const SizedBox(width: 8),
          _buildFilterChip(
            label: '💬 对话',
            active: _showDialogue,
            color: const Color(0xFF4ECDC4),
            onToggle: () => setState(() => _showDialogue = !_showDialogue),
          ),
          const SizedBox(width: 6),
          _buildFilterChip(
            label: '🔀 分支',
            active: _showChoice,
            color: const Color(0xFFFFA726),
            onToggle: () => setState(() => _showChoice = !_showChoice),
          ),
          const SizedBox(width: 6),
          _buildFilterChip(
            label: '🏁 结局',
            active: _showEnding,
            color: const Color(0xFFE74C3C),
            onToggle: () => setState(() => _showEnding = !_showEnding),
          ),
          const Spacer(),
          // 全部显示/隐藏快捷按钮
          GestureDetector(
            onTap: () => setState(() {
              _showDialogue = true;
              _showChoice = true;
              _showEnding = true;
            }),
            child: Container(
              padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4),
              decoration: BoxDecoration(
                color: Colors.white.withOpacity(0.08),
                borderRadius: BorderRadius.circular(6),
              ),
              child: const Text(
                '全部',
                style: TextStyle(color: Colors.white54, fontSize: 11),
              ),
            ),
          ),
        ],
      ),
    );
  }

  Widget _buildFilterChip({
    required String label,
    required bool active,
    required Color color,
    required VoidCallback onToggle,
  }) {
    return GestureDetector(
      onTap: onToggle,
      child: Container(
        padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4),
        decoration: BoxDecoration(
          color:
              active ? color.withOpacity(0.2) : Colors.white.withOpacity(0.05),
          borderRadius: BorderRadius.circular(8),
          border: Border.all(
            color:
                active ? color.withOpacity(0.5) : Colors.white.withOpacity(0.1),
          ),
        ),
        child: Text(
          label,
          style: TextStyle(
            color: active ? color : Colors.white38,
            fontSize: 11,
            fontWeight: active ? FontWeight.w600 : FontWeight.normal,
          ),
        ),
      ),
    );
  }

  /// 构建缩放比例指示器
  Widget _buildScaleIndicator() {
    return Container(
      padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4),
      decoration: BoxDecoration(
        color: Colors.black.withOpacity(0.6),
        borderRadius: BorderRadius.circular(8),
        border: Border.all(color: Colors.white.withOpacity(0.1)),
      ),
      child: Row(
        mainAxisSize: MainAxisSize.min,
        children: [
          const Icon(Icons.zoom_in, color: Colors.white54, size: 12),
          const SizedBox(width: 4),
          Text(
            '${(_currentScale * 100).toStringAsFixed(0)}%',
            style: const TextStyle(
              color: Colors.white70,
              fontSize: 11,
              fontFamily: 'monospace',
            ),
          ),
        ],
      ),
    );
  }

  Widget _buildStatItem(IconData icon, String label, int count, Color color,
      {String? suffix}) {
    return Row(
      mainAxisSize: MainAxisSize.min,
      children: [
        Icon(icon, color: color, size: 14),
        const SizedBox(width: 4),
        Text(
          '$label ',
          style: const TextStyle(color: Colors.white54, fontSize: 11),
        ),
        Text(
          '$count${suffix ?? ''}',
          style: TextStyle(
            color: color,
            fontSize: 12,
            fontWeight: FontWeight.bold,
          ),
        ),
      ],
    );
  }

  /// 构建单个流程图节点
  Widget _buildNodeDot({
    required StoryNode node,
    required bool isVisited,
    required bool isCurrent,
    required VoidCallback onTap,
  }) {
    final Color dotColor = _getNodeColor(node);
    final double dotSize = isCurrent ? 26 : (isVisited ? 20 : 16);
    final String label = isCurrent
        ? '📍 当前'
        : isVisited
            ? '✓ 已读'
            : '○ 未读';

    final IconData typeIcon = _getNodeTypeIcon(node);

    return Positioned(
      left: node.x - dotSize / 2,
      top: node.y - dotSize / 2,
      child: GestureDetector(
        onTap: onTap,
        child: Column(
          mainAxisSize: MainAxisSize.min,
          children: [
            // 呼吸光晕（当前节点）
            if (isCurrent) _buildBreathingGlow(dotSize, dotColor),

            // 节点圆点
            Container(
              width: dotSize + 16,
              height: dotSize + 16,
              decoration: BoxDecoration(
                shape: BoxShape.circle,
                color: dotColor
                    .withOpacity(isCurrent ? 1.0 : (isVisited ? 0.85 : 0.6)),
                border: Border.all(
                  color: isCurrent
                      ? Colors.white
                      : dotColor.withOpacity(isVisited ? 0.6 : 0.3),
                  width: isCurrent ? 3 : (isVisited ? 2 : 1.2),
                ),
                boxShadow: isCurrent
                    ? [
                        BoxShadow(
                          color: dotColor.withOpacity(0.6),
                          blurRadius: 12,
                          spreadRadius: 2,
                        ),
                      ]
                    : null,
              ),
              child: Center(
                child: Icon(
                  typeIcon,
                  color: Colors.white,
                  size: isCurrent ? 16 : 12,
                ),
              ),
            ),

            const SizedBox(height: 4),

            // 节点名称标签
            Container(
              constraints: const BoxConstraints(maxWidth: 100),
              padding: const EdgeInsets.symmetric(horizontal: 6, vertical: 2),
              decoration: BoxDecoration(
                color: Colors.black.withOpacity(0.7),
                borderRadius: BorderRadius.circular(4),
                border: Border.all(
                  color: isCurrent
                      ? Colors.amber.withOpacity(0.4)
                      : Colors.transparent,
                ),
              ),
              child: Text(
                _getNodeLabel(node),
                style: TextStyle(
                  color: isCurrent ? Colors.amber : Colors.white70,
                  fontSize: 10,
                  fontWeight: isCurrent ? FontWeight.bold : FontWeight.normal,
                ),
                textAlign: TextAlign.center,
                maxLines: 1,
                overflow: TextOverflow.ellipsis,
              ),
            ),

            // 状态标签
            Text(
              label,
              style: TextStyle(
                color: dotColor.withOpacity(isCurrent ? 1 : 0.6),
                fontSize: 8,
                fontWeight: isCurrent ? FontWeight.bold : FontWeight.normal,
              ),
            ),
          ],
        ),
      ),
    );
  }

  /// 根据节点状态和类型获取颜色
  Color _getNodeColor(StoryNode node) {
    return node.type == NodeType.ending
        ? const Color(0xFFE74C3C) // 结局 - 红色
        : node.type == NodeType.choice
            ? const Color(0xFFFFA726) // 选择 - 橙色
            : const Color(0xFF4ECDC4); // 对话 - 青色
  }

  /// 获取节点类型中文标签
  String _getNodeTypeLabel(StoryNode node) {
    switch (node.type) {
      case NodeType.dialogue:
        return '💬 对话';
      case NodeType.choice:
        return '🔀 分支';
      case NodeType.ending:
        return '🏁 结局';
    }
  }

  /// 当前节点呼吸光晕动画
  Widget _buildBreathingGlow(double dotSize, Color color) {
    return SizedBox(
      width: dotSize + 44,
      height: dotSize + 44,
      child: CustomPaint(painter: _GlowPainter(color: color)),
    );
  }

  /// 获取节点类型图标
  IconData _getNodeTypeIcon(StoryNode node) {
    switch (node.type) {
      case NodeType.dialogue:
        return Icons.chat_bubble_outline;
      case NodeType.choice:
        return Icons.alt_route;
      case NodeType.ending:
        return Icons.flag;
    }
  }

  /// 获取节点简短标签
  String _getNodeLabel(StoryNode node) {
    // 结局节点优先显示结局名称
    if (node.type == NodeType.ending && node.endingName != null) {
      final name = node.endingName!;
      if (name.length > 10) return '${name.substring(0, 10)}…';
      return name;
    }
    // 选择节点显示简短文本
    if (node.type == NodeType.choice) {
      final text = node.question ?? node.text;
      if (text.length > 10) return '${text.substring(0, 10)}…';
      return text;
    }
    // 对话节点显示说话人: 文本开头
    final prefix = node.speaker.length <= 3 ? '${node.speaker}: ' : '';
    final display = '$prefix${node.text.replaceAll('\n', ' ')}';
    if (display.length > 10) return '${display.substring(0, 10)}…';
    return display;
  }

  /// 构建图例项
  Widget _buildLegendItem(Color color, String label) {
    return Row(
      mainAxisSize: MainAxisSize.min,
      children: [
        Container(
          width: 10,
          height: 10,
          decoration: BoxDecoration(
            shape: BoxShape.circle,
            color: color,
          ),
        ),
        const SizedBox(width: 3),
        Text(
          label,
          style: const TextStyle(color: Colors.white70, fontSize: 11),
        ),
      ],
    );
  }

  /// 计算画布宽度
  double _calculateCanvasWidth(List<StoryNode> nodes) {
    if (nodes.isEmpty) return 800;
    final maxX = nodes.map((n) => n.x).reduce(math.max);
    return math.max(maxX + 200, 800);
  }

  /// 计算画布高度
  double _calculateCanvasHeight(List<StoryNode> nodes) {
    if (nodes.isEmpty) return 1050;
    final maxY = nodes.map((n) => n.y).reduce(math.max);
    return math.max(maxY + 200, 1050);
  }
}

// ==================== 连线绘制器 ====================

/// 使用 CustomPaint 绘制节点之间的贝塞尔曲线连线
class _ConnectionPainter extends CustomPainter {
  final List<List<String>> connections;
  final List<StoryNode> nodes;
  final List<String> visitedIds;
  final Map<String, String> choiceLabels;

  _ConnectionPainter({
    required this.connections,
    required this.nodes,
    required this.visitedIds,
    this.choiceLabels = const {},
  });

  @override
  void paint(Canvas canvas, Size size) {
    final nodeMap = <String, StoryNode>{};
    for (final node in nodes) {
      nodeMap[node.id] = node;
    }

    // 分支索引分配颜色
    final branchColors = [
      const Color(0xFF4CAF50), // 分支A - 绿色
      const Color(0xFFFF9800), // 分支B - 橙色
      const Color(0xFF2196F3), // 分支C - 蓝色
      const Color(0xFFE91E63), // 分支D - 粉色
    ];

    // 统计每个父节点的分支编号
    final branchIndexMap = <String, int>{};

    for (final conn in connections) {
      final from = nodeMap[conn[0]];
      final to = nodeMap[conn[1]];
      if (from == null || to == null) continue;

      // 分配分支索引
      branchIndexMap[conn[0]] ??= 0;
      final branchIdx = from.type == NodeType.choice
          ? (branchIndexMap[conn[0]]! % branchColors.length)
          : 0;
      if (from.type == NodeType.choice) {
        branchIndexMap[conn[0]] = branchIndexMap[conn[0]]! + 1;
      }

      // 判断连线两端是否都已访问
      final fromVisited = visitedIds.contains(from.id);
      final toVisited = visitedIds.contains(to.id);
      final isPathVisited = fromVisited && toVisited;

      // 分支颜色：已走路径用分支色，未走用灰色
      final branchColor = from.type == NodeType.choice
          ? branchColors[branchIdx]
          : const Color(0xFF4ECDC4);

      final paint = Paint()
        ..color = isPathVisited
            ? branchColor.withOpacity(0.7)
            : Colors.grey.withOpacity(0.25)
        ..strokeWidth = isPathVisited ? 3.0 : 1.5
        ..style = PaintingStyle.stroke;

      // 起点和终点
      final startPoint = Offset(from.x, from.y);
      final endPoint = Offset(to.x, to.y);

      // 计算贝塞尔曲线控制点（带偏移避免重叠）
      final dx = endPoint.dx - startPoint.dx;
      final dy = (endPoint.dy - startPoint.dy).abs();
      final controlOffset = dy * 0.3;

      // 对不同分支应用水平偏移
      final branchOffset = (branchIdx - 1) * 20.0;

      final cp1 = Offset(
        startPoint.dx + branchOffset * 0.3,
        startPoint.dy + controlOffset,
      );
      final cp2 = Offset(
        endPoint.dx + branchOffset * 0.3,
        endPoint.dy - controlOffset,
      );

      // 绘制贝塞尔曲线
      final path = Path()
        ..moveTo(startPoint.dx, startPoint.dy)
        ..cubicTo(cp1.dx, cp1.dy, cp2.dx, cp2.dy, endPoint.dx, endPoint.dy);
      canvas.drawPath(path, paint);

      // 如果选择节点，在连线中点画分支标签
      if (from.type == NodeType.choice) {
        final connKey = '${from.id}->${to.id}';
        final label = choiceLabels[connKey];
        if (label != null && label.isNotEmpty) {
          final midX = (cp1.dx + cp2.dx) / 2;
          final midY = (cp1.dy + cp2.dy) / 2;

          // 分支标签背景
          final bgPaint = Paint()
            ..color = Colors.black.withOpacity(0.7)
            ..style = PaintingStyle.fill;

          final textPainter = TextPainter(
            text: TextSpan(
              text: label,
              style: TextStyle(
                color: branchColor,
                fontSize: 9,
                fontWeight: FontWeight.w600,
              ),
            ),
            textDirection: TextDirection.ltr,
          )..layout(maxWidth: 80);

          final bgRect = RRect.fromRectAndRadius(
            Rect.fromCenter(
              center: Offset(midX, midY - 8),
              width: textPainter.width + 10,
              height: textPainter.height + 4,
            ),
            const Radius.circular(4),
          );
          canvas.drawRRect(bgRect, bgPaint);
          textPainter.paint(
            canvas,
            Offset(midX - textPainter.width / 2,
                midY - textPainter.height / 2 - 8),
          );
        }
      }

      // 绘制终点箭头
      _drawArrow(canvas, cp2, endPoint, paint);
    }
  }

  /// 绘制小箭头
  void _drawArrow(Canvas canvas, Offset from, Offset to, Paint paint) {
    final direction = (to - from);
    final distance = direction.distance;
    if (distance == 0) return;

    final unit = direction / distance;
    final normal = Offset(-unit.dy, unit.dx);

    final arrowSize = 8.0;
    final arrowPoint = to;
    final arrowLeft = to - unit * arrowSize + normal * arrowSize * 0.5;
    final arrowRight = to - unit * arrowSize - normal * arrowSize * 0.5;

    final arrowPath = Path()
      ..moveTo(arrowPoint.dx, arrowPoint.dy)
      ..lineTo(arrowLeft.dx, arrowLeft.dy)
      ..lineTo(arrowRight.dx, arrowRight.dy)
      ..close();

    canvas.drawPath(arrowPath, Paint()..color = paint.color);
  }

  @override
  bool shouldRepaint(covariant _ConnectionPainter oldDelegate) {
    return oldDelegate.connections != connections ||
        oldDelegate.visitedIds != visitedIds ||
        oldDelegate.choiceLabels != choiceLabels;
  }
}

// ==================== 呼吸光晕绘制器 ====================

/// 当前节点的呼吸光晕效果
class _GlowPainter extends CustomPainter {
  final Color color;

  _GlowPainter({required this.color});

  @override
  void paint(Canvas canvas, Size size) {
    final center = size.center(Offset.zero);
    final radius = size.width / 2;
    final now = DateTime.now().millisecondsSinceEpoch;
    final pulse = (math.sin(now / 800 * math.pi * 2) + 1) / 2;

    final paint = Paint()
      ..color = color.withOpacity(0.3 * pulse)
      ..maskFilter = const MaskFilter.blur(BlurStyle.normal, 10);

    canvas.drawCircle(center, radius * 0.8, paint);
  }

  @override
  bool shouldRepaint(covariant _GlowPainter oldDelegate) {
    return true; // 持续重绘以实现呼吸动画
  }
}
