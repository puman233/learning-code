import 'dart:convert';
import 'package:flutter/services.dart';
import '../models/character.dart';

/// 角色服务
///
/// 负责加载 characters.json，提供角色查询和缓存功能。
/// 单例模式，全局共享角色数据。
class CharacterService {
  static final CharacterService _instance = CharacterService._internal();
  factory CharacterService() => _instance;
  CharacterService._internal();

  /// 角色 ID → Character 映射表
  final Map<String, Character> _characters = {};

  /// 是否已加载
  bool _isLoaded = false;

  /// 所有角色列表
  List<Character> get allCharacters => _characters.values.toList();

  /// 是否已加载完成
  bool get isLoaded => _isLoaded;

  /// 从 assets/data/characters.json 加载角色数据
  Future<void> loadCharacters() async {
    if (_isLoaded) return;

    try {
      final jsonString = await rootBundle.loadString(
        'assets/data/characters.json',
      );
      final data = jsonDecode(jsonString) as Map<String, dynamic>;
      final charactersList = data['characters'] as List<dynamic>;

      _characters.clear();
      for (final charJson in charactersList) {
        final character = Character.fromJson(charJson as Map<String, dynamic>);
        _characters[character.id] = character;
      }

      _isLoaded = true;
    } catch (e) {
      // 角色文件加载失败时静默处理，使用内置默认色
      _isLoaded = false;
    }
  }

  /// 根据角色 ID 获取角色信息
  /// 若未找到则返回一个临时角色对象
  Character getCharacter(String id) {
    if (_characters.containsKey(id)) {
      return _characters[id]!;
    }

    // 尝试将 ID 映射为名称（兼容 speaker 模式）
    return Character(id: id, name: id, avatar: '$id.png', description: '');
  }

  /// 根据说话人名称查找角色
  /// 遍历所有角色，匹配 name 字段
  Character? findByName(String name) {
    try {
      return _characters.values.firstWhere((c) => c.name == name);
    } catch (_) {
      return null;
    }
  }

  /// 获取角色的主题色
  Color? getCharacterColor(String characterId) {
    final char = _characters[characterId];
    return char?.themeColor ?? Character.defaultColorFor(characterId);
  }
}
