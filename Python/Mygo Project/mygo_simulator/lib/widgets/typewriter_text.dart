import 'dart:async';
import 'package:flutter/material.dart';

/// 逐字打印文本组件
/// 模拟视觉小说中文字逐个出现的打字效果
/// 支持跳过（瞬间完整显示）和暂停/恢复
class TypewriterText extends StatefulWidget {
  /// 要显示的完整文本
  final String text;

  /// 每显示一个字的时间间隔（秒）
  final double speed;

  /// 文本样式
  final TextStyle? style;

  /// 文本对齐方式
  final TextAlign textAlign;

  /// 文字打印完成回调
  final VoidCallback? onComplete;

  /// 是否自动开始打印
  final bool autoStart;

  const TypewriterText({
    super.key,
    required this.text,
    this.speed = 0.08,
    this.style,
    this.textAlign = TextAlign.left,
    this.onComplete,
    this.autoStart = true,
  });

  @override
  State<TypewriterText> createState() => TypewriterTextState();
}

class TypewriterTextState extends State<TypewriterText> {
  /// 当前已显示的文字索引
  int _displayedCharIndex = 0;

  /// 定时器
  Timer? _timer;

  /// 是否已完成打印
  bool _isComplete = false;

  /// 是否已跳过（玩家点击跳过触发）
  bool _isSkipped = false;

  @override
  void initState() {
    super.initState();
    if (widget.autoStart) {
      _startTyping();
    }
  }

  @override
  void didUpdateWidget(TypewriterText oldWidget) {
    super.didUpdateWidget(oldWidget);
    // 如果文本变了，重置并重新开始
    if (oldWidget.text != widget.text) {
      _resetAndStart();
    }
  }

  @override
  void dispose() {
    _timer?.cancel();
    super.dispose();
  }

  /// 开始打字效果
  void _startTyping() {
    _timer?.cancel();
    _displayedCharIndex = 0;
    _isComplete = false;
    _isSkipped = false;

    if (widget.text.isEmpty) {
      _isComplete = true;
      widget.onComplete?.call();
      return;
    }

    _timer = Timer.periodic(
      Duration(milliseconds: (widget.speed * 1000).round()),
      (timer) {
        if (_displayedCharIndex < widget.text.length) {
          setState(() {
            _displayedCharIndex++;
          });
        } else {
          _timer?.cancel();
          _isComplete = true;
          widget.onComplete?.call();
        }
      },
    );
  }

  /// 重置并重新开始
  void _resetAndStart() {
    _timer?.cancel();
    _startTyping();
  }

  /// 跳过动画，瞬间显示完整文本
  void skip() {
    if (_isComplete) return;
    _timer?.cancel();
    setState(() {
      _displayedCharIndex = widget.text.length;
      _isComplete = true;
      _isSkipped = true;
    });
    widget.onComplete?.call();
  }

  /// 获取当前显示的文本
  String get displayedText =>
      widget.text.substring(0, _displayedCharIndex);

  /// 打字是否已完成
  bool get isComplete => _isComplete;

  /// 是否已被跳过
  bool get isSkipped => _isSkipped;

  @override
  Widget build(BuildContext context) {
    return Text(
      displayedText,
      style: widget.style,
      textAlign: widget.textAlign,
    );
  }
}
