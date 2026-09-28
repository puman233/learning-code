import 'package:flutter/material.dart';
import '../models/story_node.dart';
import '../models/character.dart';
import '../services/character_service.dart';
import 'typewriter_text.dart';
import 'character_avatar.dart';

/// 对话气泡组件
/// 视觉小说风格的底部半透明对话框，包含说话人头像和逐字打印文本
class DialogueBox extends StatefulWidget {
  /// 当前剧情节点
  final StoryNode node;

  /// 打字完成回调
  final VoidCallback? onTypewriterComplete;

  /// 点击对话框回调（用于"继续"操作）
  final VoidCallback? onTap;

  /// 是否正在过渡动画中
  final bool isTransitioning;

  const DialogueBox({
    super.key,
    required this.node,
    this.onTypewriterComplete,
    this.onTap,
    this.isTransitioning = false,
  });

  @override
  State<DialogueBox> createState() => _DialogueBoxState();
}

class _DialogueBoxState extends State<DialogueBox> {
  final GlobalKey<TypewriterTextState> _typewriterKey = GlobalKey();
  bool _isTextComplete = false;

  @override
  void didUpdateWidget(DialogueBox oldWidget) {
    super.didUpdateWidget(oldWidget);
    // 节点变化时重置文字完成状态
    if (oldWidget.node.id != widget.node.id) {
      _isTextComplete = false;
    }
  }

  void _onTypewriterDone() {
    setState(() {
      _isTextComplete = true;
    });
    widget.onTypewriterComplete?.call();
  }

  /// 跳过文字动画
  void skipTextAnimation() {
    _typewriterKey.currentState?.skip();
  }

  /// 打字是否已完成
  bool get isTextComplete => _isTextComplete;

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: () {
        // 如果打字未完成，点击跳字；如果已完成，触发继续回调
        if (!_isTextComplete) {
          skipTextAnimation();
        } else {
          widget.onTap?.call();
        }
      },
      child: Container(
        margin: const EdgeInsets.only(bottom: 16, left: 16, right: 16),
        decoration: BoxDecoration(
          // 毛玻璃效果：半透明黑色背景 + 模糊
          color: Colors.black.withOpacity(0.65),
          borderRadius: BorderRadius.circular(20),
          border: Border.all(color: Colors.white.withOpacity(0.15), width: 1),
        ),
        child: ClipRRect(
          borderRadius: BorderRadius.circular(20),
          child: BackdropFilter(
            filter: widget.isTransitioning
                ? (ColorFilter.mode(
                    Colors.black.withOpacity(0.5),
                    BlendMode.srcOver,
                  ))
                : (ColorFilter.mode(Colors.transparent, BlendMode.srcOver)),
            child: Padding(
              padding: const EdgeInsets.all(20),
              child: Row(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  // 角色头像（左侧）
                  _buildAvatar(),
                  const SizedBox(width: 16),
                  // 说话人名称 + 文本内容
                  Expanded(
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        // 说话人名称
                        Text(
                          widget.node.speaker,
                          style: TextStyle(
                            color: _getSpeakerColor(widget.node.speaker),
                            fontSize: 16,
                            fontWeight: FontWeight.bold,
                          ),
                        ),
                        const SizedBox(height: 8),
                        // 逐字打印文本
                        Flexible(
                          child: TypewriterText(
                            key: _typewriterKey,
                            text: widget.node.text,
                            speed: 0.08,
                            style: const TextStyle(
                              color: Colors.white,
                              fontSize: 18,
                              height: 1.6,
                              letterSpacing: 0.5,
                            ),
                            textAlign: TextAlign.left,
                            onComplete: _onTypewriterDone,
                          ),
                        ),
                      ],
                    ),
                  ),
                ],
              ),
            ),
          ),
        ),
      ),
    );
  }

  /// 构建角色头像
  Widget _buildAvatar() {
    // 若是系统或旁白，不显示头像
    if (widget.node.speaker == '系统' || widget.node.speaker == '旁白') {
      return const SizedBox.shrink();
    }

    final characterService = CharacterService();
    final Character character;

    // 优先通过 characterId 查找，其次通过 speaker 名称查找
    if (widget.node.characterId != null) {
      character = characterService.getCharacter(widget.node.characterId!);
    } else {
      character =
          characterService.findByName(widget.node.speaker) ??
          Character(
            id: widget.node.speaker,
            name: widget.node.speaker,
            avatar: '${widget.node.speaker}.png',
          );
    }

    return CharacterAvatar(
      character: character,
      size: 80,
      showGlow: true,
      borderColor: _getSpeakerColor(widget.node.speaker),
    );
  }

  /// 根据说话人返回主题色
  Color _getSpeakerColor(String speaker) {
    // 尝试从角色服务获取主题色
    final characterService = CharacterService();
    final color = characterService.getCharacterColor(speaker);
    if (color != null) return color;

    // 如果未找到，回退到硬编码映射
    switch (speaker) {
      case '爱音':
        return const Color(0xFFFF6B9D);
      case '灯':
        return const Color(0xFF9B59B6);
      case '素世':
        return const Color(0xFF4ECDC4);
      case '立希':
        return const Color(0xFF2196F3);
      case '乐奈':
        return const Color(0xFFFFA726);
      case '系统':
        return const Color(0xFF95A5A6);
      case '旁白':
        return const Color(0xFFF5F5DC);
      default:
        return Colors.white;
    }
  }
}
