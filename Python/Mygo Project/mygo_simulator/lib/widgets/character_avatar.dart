import 'package:flutter/material.dart';
import '../models/character.dart';

/// 角色头像组件
///
/// 视觉小说风格的角色头像显示，支持：
/// - 圆形裁剪头像
/// - 彩色描边（根据角色主题色）
/// - 头像缺失时显示名称首字占位
/// - 可选的呼吸光晕动画
class CharacterAvatar extends StatelessWidget {
  /// 角色数据
  final Character character;

  /// 头像尺寸
  final double size;

  /// 是否显示呼吸光晕
  final bool showGlow;

  /// 是否禁用（灰显）
  final bool isDimmed;

  /// 额外的边框颜色
  final Color? borderColor;

  const CharacterAvatar({
    super.key,
    required this.character,
    this.size = 80,
    this.showGlow = false,
    this.isDimmed = false,
    this.borderColor,
  });

  @override
  Widget build(BuildContext context) {
    final themeColor =
        borderColor ??
        character.themeColor ??
        Character.defaultColorFor(character.id);

    return Column(
      mainAxisSize: MainAxisSize.min,
      children: [
        // 头像光晕（可选）
        if (showGlow)
          Container(
            width: size + 16,
            height: size + 16,
            decoration: BoxDecoration(
              shape: BoxShape.circle,
              boxShadow: [
                BoxShadow(
                  color: themeColor.withOpacity(0.4),
                  blurRadius: 16,
                  spreadRadius: 2,
                ),
              ],
            ),
          ),

        // 头像主体
        Container(
          width: size,
          height: size,
          decoration: BoxDecoration(
            shape: BoxShape.circle,
            border: Border.all(
              color: isDimmed
                  ? themeColor.withOpacity(0.2)
                  : themeColor.withOpacity(0.6),
              width: 2.5,
            ),
            boxShadow: [
              if (!isDimmed)
                BoxShadow(
                  color: themeColor.withOpacity(0.2),
                  blurRadius: 8,
                  spreadRadius: 1,
                ),
            ],
          ),
          child: ClipOval(
            child: Image.asset(
              character.avatarAssetPath,
              fit: BoxFit.cover,
              errorBuilder: (context, error, stackTrace) => Container(
                color: themeColor.withOpacity(0.15),
                child: Center(
                  child: Text(
                    character.name.isNotEmpty ? character.name[0] : '?',
                    style: TextStyle(
                      color: isDimmed
                          ? themeColor.withOpacity(0.3)
                          : themeColor,
                      fontSize: size * 0.45,
                      fontWeight: FontWeight.bold,
                    ),
                  ),
                ),
              ),
            ),
          ),
        ),

        // 角色名称（头像下方）
        const SizedBox(height: 6),
        Text(
          character.name,
          style: TextStyle(
            color: isDimmed ? Colors.white38 : Colors.white,
            fontSize: 13,
            fontWeight: FontWeight.w600,
            letterSpacing: 1,
            shadows: [
              Shadow(color: Colors.black.withOpacity(0.6), blurRadius: 4),
            ],
          ),
        ),
      ],
    );
  }
}
