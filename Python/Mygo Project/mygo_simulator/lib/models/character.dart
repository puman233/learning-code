import 'dart:ui';
import 'package:flutter/material.dart';

/// 角色数据模型
///
/// 表示剧情中的一个角色，包含其标识、名称、头像及描述信息。
/// 支持通过角色 ID 快速查找对应的头像资源和主题色。
class Character {
  /// 角色唯一标识（如 "rikki", "tomori"）
  final String id;

  /// 角色显示名称（如 "立希", "灯"）
  final String name;

  /// 头像图片路径（相对于 assets/images/characters/）
  final String avatar;

  /// 角色描述/简介
  final String description;

  /// 角色主题色（用于对话框边框、名称高亮等）
  final String? themeColorHex;

  const Character({
    required this.id,
    required this.name,
    required this.avatar,
    this.description = '',
    this.themeColorHex,
  });

  /// 从 JSON 字典构造 Character
  factory Character.fromJson(Map<String, dynamic> json) {
    return Character(
      id: json['id'] as String,
      name: json['name'] as String,
      avatar: json['avatar'] as String,
      description: (json['description'] as String?) ?? '',
      themeColorHex: json['themeColor'] as String?,
    );
  }

  /// 转换为 JSON 字典
  Map<String, dynamic> toJson() {
    return {
      'id': id,
      'name': name,
      'avatar': avatar,
      'description': description,
      if (themeColorHex != null) 'themeColor': themeColorHex,
    };
  }

  /// 获取角色的主题 Color 对象
  /// 若未配置则返回 null
  Color? get themeColor {
    if (themeColorHex == null) return null;
    try {
      final hex = themeColorHex!.replaceFirst('#', '');
      final value = int.parse(hex, radix: 16);
      return Color(value | 0xFF000000);
    } catch (_) {
      return null;
    }
  }

  /// 获取角色头像的完整资源路径
  String get avatarAssetPath => 'assets/images/characters/$avatar';

  // ==================== 预置角色查找表 ====================

  /// 已知角色 ID → 默认主题色映射
  static const Map<String, Color> _defaultColors = {
    'anon': Color(0xFFFF6B9D), // 爱音 - 粉色
    'tomori': Color(0xFF9B59B6), // 灯 - 紫色
    'soyo': Color(0xFF4ECDC4), // 素世 - 青色
    'rikki': Color(0xFF2196F3), // 立希 - 蓝色
    'rana': Color(0xFFFFA726), // 乐奈 - 橙色
    'sakiko': Color(0xFFE74C3C), // 祥子 - 红色
    'mutsumi': Color(0xFF2ECC71), // 睦 - 绿色
    'umiri': Color(0xFF1ABC9C), // 海铃 - 绿松石
    'nyamu': Color(0xFFE91E63), // 喵梦 - 粉红
  };

  /// 根据角色 ID 获取默认主题色
  static Color defaultColorFor(String id) {
    return _defaultColors[id.toLowerCase()] ?? Colors.white;
  }
}
