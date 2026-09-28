import 'dart:ui';
import 'package:flutter/material.dart';

/// 背景视图组件
///
/// 视觉小说风格的背景展示，支持：
/// - 图片背景
/// - 渐变色占位背景（图片缺失时）
/// - 淡入淡出过渡动画
/// - 可选的模糊效果
/// - 暗色蒙层
class BackgroundView extends StatefulWidget {
  /// 背景图片文件名（assets/images/backgrounds/ 下）
  final String? backgroundImage;

  /// 是否启用模糊效果
  final bool enableBlur;

  /// 模糊强度（sigma 值）
  final double blurStrength;

  /// 暗色蒙层透明度
  final double overlayOpacity;

  /// 子组件标识（用于触发过渡动画）
  final Key? transitionKey;

  const BackgroundView({
    super.key,
    this.backgroundImage,
    this.enableBlur = false,
    this.blurStrength = 4.0,
    this.overlayOpacity = 0.35,
    this.transitionKey,
  });

  @override
  State<BackgroundView> createState() => _BackgroundViewState();
}

class _BackgroundViewState extends State<BackgroundView>
    with SingleTickerProviderStateMixin {
  /// 淡入淡出动画控制器
  late AnimationController _fadeController;
  late Animation<double> _fadeAnimation;

  /// 当前背景（用于交叉淡入淡出）
  String? _previousImage;
  String? _currentImage;

  @override
  void initState() {
    super.initState();
    _fadeController = AnimationController(
      vsync: this,
      duration: const Duration(milliseconds: 600),
    );
    _fadeAnimation = CurvedAnimation(
      parent: _fadeController,
      curve: Curves.easeInOut,
    );

    _currentImage = widget.backgroundImage;
    // 首次加载立即显示
    _fadeController.value = 1.0;
  }

  @override
  void didUpdateWidget(BackgroundView oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (oldWidget.backgroundImage != widget.backgroundImage &&
        widget.backgroundImage != null) {
      // 背景变化：旧图保留，新图淡入
      setState(() {
        _previousImage = _currentImage;
        _currentImage = widget.backgroundImage;
      });
      _fadeController.forward(from: 0.0);
    }
  }

  @override
  void dispose() {
    _fadeController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Stack(
      children: [
        // 旧背景（淡出中）
        if (_previousImage != null && _fadeController.value < 1.0)
          Positioned.fill(child: _buildImage(_previousImage!)),

        // 新背景（淡入中）
        AnimatedBuilder(
          animation: _fadeAnimation,
          builder: (context, child) {
            return Opacity(opacity: _fadeAnimation.value, child: child);
          },
          child: _currentImage != null
              ? _buildImage(_currentImage!)
              : _buildGradientPlaceholder(),
        ),

        // 暗色蒙层
        Positioned.fill(
          child: Container(
            color: Colors.black.withOpacity(widget.overlayOpacity),
          ),
        ),

        // 模糊效果（最上层）
        if (widget.enableBlur) Positioned.fill(child: _buildBlurOverlay()),
      ],
    );
  }

  /// 构建背景图片 — 等比例裁剪填满，不留黑边、不拉伸变形
  Widget _buildImage(String imageName) {
    // 使用 LayoutBuilder 获取父容器实际尺寸，确保图片填满
    return LayoutBuilder(
      builder: (context, constraints) {
        return SizedBox(
          width:
              constraints.maxWidth > 0 ? constraints.maxWidth : double.infinity,
          height: constraints.maxHeight > 0
              ? constraints.maxHeight
              : double.infinity,
          child: Image.asset(
            'assets/images/backgrounds/$imageName',
            fit: BoxFit.cover,
            width: constraints.maxWidth > 0
                ? constraints.maxWidth
                : double.infinity,
            height: constraints.maxHeight > 0
                ? constraints.maxHeight
                : double.infinity,
            errorBuilder: (context, error, stackTrace) {
              return _buildGradientPlaceholder();
            },
          ),
        );
      },
    );
  }

  /// 构建渐变色占位背景
  Widget _buildGradientPlaceholder() {
    return Container(
      decoration: const BoxDecoration(
        gradient: LinearGradient(
          colors: [Color(0xFF0D0221), Color(0xFF150534), Color(0xFF1A0A3E)],
          begin: Alignment.topCenter,
          end: Alignment.bottomCenter,
        ),
      ),
    );
  }

  /// 构建模糊叠加层
  Widget _buildBlurOverlay() {
    return ClipRect(
      child: BackdropFilter(
        filter: ImageFilter.blur(
          sigmaX: widget.blurStrength,
          sigmaY: widget.blurStrength,
        ),
        child: Container(color: Colors.transparent),
      ),
    );
  }
}
