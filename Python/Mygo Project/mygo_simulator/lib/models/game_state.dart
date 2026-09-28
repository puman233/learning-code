import 'dart:convert';
import 'story_node.dart';

/// 游戏状态模型
/// 管理当前游戏运行时全部可变状态，支持序列化到本地存档
class GameState {
  /// 当前所在节点 ID
  String currentNodeId;

  /// 已访问过的所有节点 ID 列表（按访问顺序）
  List<String> visitedNodeIds;

  /// 已解锁的结局 ID 列表
  List<int> unlockedEndings;

  /// 当前是否处于文字打印中
  bool isTextAnimating;

  /// 当前是否处于过渡动画中（节点切换时的淡入淡出）
  bool isTransitioning;

  /// 当前节点是否不可交互（防连点）
  bool isLocked;

  GameState({
    required this.currentNodeId,
    List<String>? visitedNodeIds,
    List<int>? unlockedEndings,
    this.isTextAnimating = false,
    this.isTransitioning = false,
    this.isLocked = false,
  })  : visitedNodeIds = visitedNodeIds ?? [],
        unlockedEndings = unlockedEndings ?? [];

  /// 创建一个全新的初始游戏状态
  factory GameState.initial(String startNodeId) {
    return GameState(currentNodeId: startNodeId);
  }

  /// 标记当前节点为已访问
  void markCurrentVisited() {
    if (!visitedNodeIds.contains(currentNodeId)) {
      visitedNodeIds.add(currentNodeId);
    }
  }

  /// 切换到指定节点
  void navigateTo(String nodeId) {
    currentNodeId = nodeId;
    markCurrentVisited();
  }

  /// 记录已解锁结局
  void unlockEnding(int endingId) {
    if (!unlockedEndings.contains(endingId)) {
      unlockedEndings.add(endingId);
    }
  }

  /// 检查某个结局是否已解锁
  bool isEndingUnlocked(int endingId) {
    return unlockedEndings.contains(endingId);
  }

  /// 重置状态（用于重新开始游戏）
  void reset(String startNodeId) {
    currentNodeId = startNodeId;
    visitedNodeIds = [startNodeId];
    // 保留已解锁结局（全局收集），不清除
    isTextAnimating = false;
    isTransitioning = false;
    isLocked = false;
  }

  /// 将 GameState 序列化为 JSON 字符串（用于存档）
  String toJson() {
    return jsonEncode({
      'currentNodeId': currentNodeId,
      'visitedNodeIds': visitedNodeIds,
      'unlockedEndings': unlockedEndings,
    });
  }

  /// 从 JSON 字符串反序列化 GameState（用于读档）
  factory GameState.fromJson(String jsonStr) {
    final map = jsonDecode(jsonStr) as Map<String, dynamic>;
    return GameState(
      currentNodeId: map['currentNodeId'] as String,
      visitedNodeIds: (map['visitedNodeIds'] as List<dynamic>)
          .cast<String>(),
      unlockedEndings: (map['unlockedEndings'] as List<dynamic>)
          .cast<int>(),
    );
  }

  /// 计算当前剧情进度百分比（基于已访问节点数 / 总节点数）
  double progressPercentage(int totalNodeCount) {
    if (totalNodeCount == 0) return 0.0;
    return (visitedNodeIds.length / totalNodeCount).clamp(0.0, 1.0);
  }
}
