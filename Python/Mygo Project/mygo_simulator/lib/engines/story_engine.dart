import 'dart:convert';
import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';
import '../models/story_node.dart';
import '../models/game_state.dart';
import '../models/choice.dart';
import '../services/character_service.dart';

/// 剧情引擎核心类（状态机）
/// 负责加载 flow.json、解析节点、执行跳转逻辑、驱动游戏流程
class StoryEngine extends ChangeNotifier {
  /// 所有节点的映射表（id -> StoryNode）
  final Map<String, StoryNode> _nodes = {};

  /// 所有结局的元数据
  final Map<int, Map<String, dynamic>> _endingsMeta = {};

  /// 角色服务
  final CharacterService _characterService = CharacterService();

  /// 历史栈（用于 back() 导航）
  final List<String> _historyStack = [];

  /// 是否已初始化
  bool _isInitialized = false;

  /// 起始节点 ID
  late String _startNodeId;

  /// 当前游戏状态
  late GameState _gameState;

  /// 当前所在节点
  StoryNode? _currentNode;

  /// 节点总数
  int get totalNodeCount => _nodes.length;

  /// 当前游戏状态
  GameState get gameState => _gameState;

  /// 当前节点
  StoryNode? get currentNode => _currentNode;

  /// 所有节点列表（用于流程图展示）
  List<StoryNode> get allNodes => _nodes.values.toList();

  /// 起始节点 ID
  String get startNodeId => _startNodeId;

  /// 所有结局元数据
  Map<int, Map<String, dynamic>> get endingsMeta => _endingsMeta;

  /// 角色服务
  CharacterService get characterService => _characterService;

  /// 历史栈大小
  int get historyLength => _historyStack.length;

  /// 是否可以返回
  bool get canGoBack => _historyStack.length >= 2;

  /// 初始化状态
  bool get isInitialized => _isInitialized;

  /// 当前节点的提问文本（若有）
  String? get currentQuestion => _currentNode?.question;

  // ==================== 生命周期 ====================

  /// 加载并解析 flow.json
  Future<void> loadFlowData() async {
    final jsonString = await rootBundle.loadString('assets/data/flow.json');
    final data = jsonDecode(jsonString) as Map<String, dynamic>;

    // 解析起始节点（兼容两种字段名：startNodeId / start）
    _startNodeId = (data['startNodeId'] ?? data['start']) as String;

    // 解析结局元数据（兼容两种结构）
    final endingsJson = data['endings'] as Map<String, dynamic>?;
    _endingsMeta.clear();
    if (endingsJson != null) {
      for (final entry in endingsJson.entries) {
        final id = int.parse(entry.key);
        _endingsMeta[id] = entry.value as Map<String, dynamic>;
      }
    }

    // 解析所有节点（兼容 nodes 或 choices 作为列表键名）
    _nodes.clear();
    final nodesList = data['nodes'] as List<dynamic>;
    for (final nodeJson in nodesList) {
      final node = StoryNode.fromJson(nodeJson as Map<String, dynamic>);
      _nodes[node.id] = node;
    }

    // 加载角色数据
    await _characterService.loadCharacters();

    _isInitialized = true;
  }

  /// 初始化新游戏（加载数据后使用）
  void startNewGame() {
    _gameState = GameState.initial(_startNodeId);
    _currentNode = _nodes[_startNodeId];
    _gameState.markCurrentVisited();
    // 初始化历史栈
    _historyStack.clear();
    _historyStack.add(_startNodeId);
    notifyListeners();
  }

  /// 从存档恢复游戏
  void restoreFromState(GameState state) {
    _gameState = state;
    _currentNode = _nodes[state.currentNodeId];
    notifyListeners();
  }

  // ==================== 核心导航 ====================

  /// 跳转到指定节点
  /// 返回目标节点，如果不存在则返回 null
  StoryNode? navigateTo(String nodeId) {
    final target = _nodes[nodeId];
    if (target == null) return null;

    _currentNode = target;
    _gameState.navigateTo(nodeId);
    // 记录历史
    _historyStack.add(nodeId);
    notifyListeners();
    return target;
  }

  /// 返回到上一个节点
  /// 返回上一个节点，如果无法返回则返回 null
  StoryNode? goBack() {
    if (!canGoBack) return null;

    // 弹出当前节点，然后取栈顶
    _historyStack.removeLast();
    final previousId = _historyStack.last;

    _currentNode = _nodes[previousId];
    _gameState.navigateTo(previousId);
    notifyListeners();
    return _currentNode;
  }

  /// 重新开始游戏（保留已解锁结局）
  void restartGame() {
    _gameState.reset(_startNodeId);
    _currentNode = _nodes[_startNodeId];
    _historyStack.clear();
    _historyStack.add(_startNodeId);
    notifyListeners();
  }

  /// 重置游戏（保留已解锁结局）- 兼容旧名称
  void resetGame() {
    restartGame();
  }

  /// 处理对话节点的"继续"操作
  /// 若当前节点有 next 则跳转，否则返回 null
  StoryNode? proceedToNext() {
    if (_currentNode == null || _currentNode!.next == null) return null;
    return navigateTo(_currentNode!.next!);
  }

  /// 处理选项选择
  /// 根据 Choice 中的 nextNode 跳转
  StoryNode? selectChoice(Choice choice) {
    return navigateTo(choice.nextNode);
  }

  /// 获取当前节点的选项列表
  List<Choice>? getCurrentChoices() {
    return _currentNode?.choices;
  }

  /// 判断当前节点是否为结局节点
  bool get isCurrentNodeEnding => _currentNode?.type == NodeType.ending;

  /// 判断当前节点是否为选项节点
  bool get isCurrentNodeChoice => _currentNode?.type == NodeType.choice;

  /// 处理结局达成：记录解锁信息
  void handleEndingReached() {
    if (_currentNode?.endingId != null) {
      _gameState.unlockEnding(_currentNode!.endingId!);
    }
  }

  /// 获取结局的星级评分
  int getEndingStars(int endingId) {
    final meta = _endingsMeta[endingId];
    return (meta?['stars'] as int?) ?? 1;
  }

  /// 获取结局名称
  String getEndingName(int endingId) {
    return _currentNode?.endingName ?? '结局 $endingId';
  }

  /// 获取当前进度百分比
  double get progress => _gameState.progressPercentage(_nodes.length);

  // ==================== 工具方法 ====================

  /// 根据 ID 获取节点
  StoryNode? getNodeById(String id) => _nodes[id];

  /// 获取从指定节点出发的连线信息（用于流程图绘制）
  /// 返回 [fromId, toId] 对列表
  List<List<String>> getConnections() {
    final connections = <List<String>>[];
    for (final node in _nodes.values) {
      if (node.type == NodeType.dialogue && node.next != null) {
        connections.add([node.id, node.next!]);
      } else if (node.type == NodeType.choice && node.choices != null) {
        for (final choice in node.choices!) {
          connections.add([node.id, choice.nextNode]);
        }
      }
    }
    return connections;
  }
}
