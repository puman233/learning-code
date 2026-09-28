/// 选项数据模型
/// 表示剧情分支中玩家可以选择的单个选项
class Choice {
  /// 选项显示文本
  final String text;

  /// 选择后跳转的目标节点 ID
  final String nextNode;

  /// 可选条件标记（预留扩展，如需要特定已解锁结局等）
  final String condition;

  const Choice({
    required this.text,
    required this.nextNode,
    this.condition = '',
  });

  /// 从 JSON 字典构造 Choice（旧格式：nextNode）
  factory Choice.fromJson(Map<String, dynamic> json) {
    return Choice(
      text: json['text'] as String,
      nextNode: json['nextNode'] as String,
      condition: (json['condition'] as String?) ?? '',
    );
  }

  /// 从 JSON 字典构造 Choice（新格式：next）
  factory Choice.fromJsonAlt(Map<String, dynamic> json) {
    return Choice(
      text: json['text'] as String,
      nextNode: json['next'] as String,
      condition: (json['condition'] as String?) ?? '',
    );
  }

  /// 转换为 JSON 字典
  Map<String, dynamic> toJson() {
    return {'text': text, 'nextNode': nextNode, 'condition': condition};
  }
}
