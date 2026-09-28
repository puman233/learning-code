import 'package:flutter/material.dart';

/// 选项按钮组件
/// 视觉小说风格的选择按钮，带点击缩放动画与涟漪效果
class ChoiceButton extends StatefulWidget {
  /// 按钮显示文本
  final String text;

  /// 点击回调
  final VoidCallback? onTap;

  /// 是否禁用（防连点）
  final bool isDisabled;

  /// 按钮主题色
  final Color? color;

  const ChoiceButton({
    super.key,
    required this.text,
    this.onTap,
    this.isDisabled = false,
    this.color,
  });

  @override
  State<ChoiceButton> createState() => _ChoiceButtonState();
}

class _ChoiceButtonState extends State<ChoiceButton>
    with SingleTickerProviderStateMixin {
  /// 缩放动画控制器
  late AnimationController _animController;
  late Animation<double> _scaleAnim;

  @override
  void initState() {
    super.initState();
    _animController = AnimationController(
      vsync: this,
      duration: const Duration(milliseconds: 150),
    );
    _scaleAnim = Tween<double>(begin: 1.0, end: 0.95).animate(
      CurvedAnimation(parent: _animController, curve: Curves.easeInOut),
    );
  }

  @override
  void dispose() {
    _animController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return AnimatedBuilder(
      animation: _scaleAnim,
      builder: (context, child) {
        return Transform.scale(
          scale: _scaleAnim.value,
          child: child,
        );
      },
      child: Material(
        color: Colors.transparent,
        child: InkWell(
          onTap: widget.isDisabled
              ? null
              : () {
                  // 按下时收缩
                  _animController.forward();
                  // 抬起时恢复并触发回调
                  Future.delayed(const Duration(milliseconds: 100), () {
                    _animController.reverse();
                    widget.onTap?.call();
                  });
                },
          borderRadius: BorderRadius.circular(16),
          splashColor:
              (widget.color ?? Colors.white).withOpacity(0.3),
          highlightColor:
              (widget.color ?? Colors.white).withOpacity(0.1),
          child: Container(
            width: double.infinity,
            padding: const EdgeInsets.symmetric(
              vertical: 16,
              horizontal: 24,
            ),
            decoration: BoxDecoration(
              gradient: LinearGradient(
                colors: [
                  (widget.color ?? Colors.white).withOpacity(0.2),
                  (widget.color ?? Colors.white).withOpacity(0.05),
                ],
                begin: Alignment.topLeft,
                end: Alignment.bottomRight,
              ),
              borderRadius: BorderRadius.circular(16),
              border: Border.all(
                color: (widget.color ?? Colors.white).withOpacity(
                    widget.isDisabled ? 0.2 : 0.5),
                width: 1.5,
              ),
            ),
            child: Center(
              child: Text(
                widget.text,
                style: TextStyle(
                  color: widget.isDisabled
                      ? Colors.white38
                      : Colors.white,
                  fontSize: 18,
                  fontWeight: FontWeight.w600,
                  letterSpacing: 1.5,
                ),
                textAlign: TextAlign.center,
              ),
            ),
          ),
        ),
      ),
    );
  }
}

// 使用 Flutter 内置的 AnimatedBuilder（自 Flutter 3.10+ 可用）
// 无需自定义实现
