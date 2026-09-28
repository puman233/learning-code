import 'choice.dart';

/// 节点类型枚举
enum NodeType {
  /// 普通对话节点
  dialogue,

  /// 选项分支节点
  choice,

  /// 结局节点
  ending,
}

/// 剧情节点数据模型
/// 表示 flow.json 中的一个节点，可以是对话、选项分支或结局
class StoryNode {
  /// 节点唯一标识
  final String id;

  /// 节点类型
  final NodeType type;

  /// 说话人名称（兼容原有字段）
  final String speaker;

  /// 角色 ID（引用 Character 模型，优先级高于 speaker）
  final String? characterId;

  /// 显示文本（支持 \n 换行）
  final String text;

  /// 可选的提问文本（显示在选项上方）
  final String? question;

  /// 背景图路径
  final String background;

  /// 仅当 type 为 dialogue 时有效，指向下一个节点 ID
  final String? next;

  /// 仅当 type 为 choice 时有效，包含所有可选分支
  final List<Choice>? choices;

  /// 仅当 type 为 ending 时有效，标记结局编号
  final int? endingId;

  /// 结局名称（仅 ending 节点）
  final String? endingName;

  /// 流程图横坐标
  final double x;

  /// 流程图纵坐标
  final double y;

  const StoryNode({
    required this.id,
    required this.type,
    required this.speaker,
    required this.text,
    required this.background,
    this.characterId,
    this.question,
    this.next,
    this.choices,
    this.endingId,
    this.endingName,
    this.x = 0,
    this.y = 0,
  });

  /// 从 JSON 字典构造 StoryNode
  factory StoryNode.fromJson(Map<String, dynamic> json) {
    // 支持兼容两种格式：
    // 格式 A（新）：{ character, text, question, options }
    // 格式 B（旧）：{ speaker, text, choices }
    final typeStr = json['type'] as String? ?? 'dialogue';

    // 检测是否为"问题+选项"模式（新格式）
    final hasOptions = json['options'] != null;
    final hasChoices = json['choices'] != null;

    // 解析选项列表
    List<Choice>? parseOptions() {
      final optionsJson = json['options'] as List<dynamic>?;
      if (optionsJson != null) {
        return optionsJson
            .map((e) => Choice.fromJsonAlt(e as Map<String, dynamic>))
            .toList();
      }
      final choicesJson = json['choices'] as List<dynamic>?;
      if (choicesJson != null) {
        return choicesJson
            .map((e) => Choice.fromJson(e as Map<String, dynamic>))
            .toList();
      }
      return null;
    }

    // 处理 characterId（新格式）和 speaker（旧格式）
    final characterId = json['character'] as String?;
    final speaker = json['speaker'] as String? ?? characterId ?? '';

    return StoryNode(
      id: json['id'] as String,
      type: _parseNodeType(typeStr),
      speaker: speaker,
      characterId: characterId,
      text: json['text'] as String? ?? '',
      question: json['question'] as String?,
      background: (json['background'] as String?) ?? 'bg_default.png',
      next: json['next'] as String?,
      choices: parseOptions(),
      endingId: json['endingId'] as int?,
      endingName: json['endingName'] as String?,
      x: (json['x'] as num?)?.toDouble() ?? 0,
      y: (json['y'] as num?)?.toDouble() ?? 0,
    );
  }

  /// 将字符串节点类型解析为枚举
  static NodeType _parseNodeType(String type) {
    switch (type) {
      case 'dialogue':
        return NodeType.dialogue;
      case 'choice':
        return NodeType.choice;
      case 'ending':
        return NodeType.ending;
      default:
        throw ArgumentError('未知的节点类型: $type');
    }
  }

  /// 转换为 JSON 字典
  Map<String, dynamic> toJson() {
    return {
      'id': id,
      'type': type.name,
      'speaker': speaker,
      'text': text,
      'background': background,
      if (next != null) 'next': next,
      if (choices != null) 'choices': choices!.map((c) => c.toJson()).toList(),
      if (endingId != null) 'endingId': endingId,
      if (endingName != null) 'endingName': endingName,
      'x': x,
      'y': y,
    };
  }
}
