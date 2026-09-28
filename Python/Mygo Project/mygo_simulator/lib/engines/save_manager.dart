import 'package:shared_preferences/shared_preferences.dart';
import 'dart:convert';
import '../models/game_state.dart';

/// 存档管理器
/// 使用 SharedPreferences 实现本地持久化存储
/// 负责存档的读写、已解锁结局的永久保存
class SaveManager {
  static const String _saveKey = 'mygo_game_save';
  static const String _endingsKey = 'mygo_unlocked_endings';
  static const String _hasSaveKey = 'mygo_has_save_data';

  /// 保存当前游戏状态到本地
  Future<bool> saveGame(GameState state) async {
    try {
      final prefs = await SharedPreferences.getInstance();
      await prefs.setString(_saveKey, state.toJson());
      // 额外持久化已解锁结局
      await prefs.setString(
        _endingsKey,
        jsonEncode(state.unlockedEndings),
      );
      await prefs.setBool(_hasSaveKey, true);
      return true;
    } catch (e) {
      // 存档失败时静默处理，不中断用户体验
      return false;
    }
  }

  /// 从本地读取游戏状态
  /// 如果没有存档则返回 null
  Future<GameState?> loadGame() async {
    try {
      final prefs = await SharedPreferences.getInstance();
      final hasSave = prefs.getBool(_hasSaveKey) ?? false;
      if (!hasSave) return null;

      final saveStr = prefs.getString(_saveKey);
      if (saveStr == null || saveStr.isEmpty) return null;

      return GameState.fromJson(saveStr);
    } catch (e) {
      // 读档失败时返回 null
      return null;
    }
  }

  /// 检查是否存在存档
  Future<bool> hasSaveData() async {
    final prefs = await SharedPreferences.getInstance();
    return prefs.getBool(_hasSaveKey) ?? false;
  }

  /// 删除当前存档（重新开始游戏时调用）
  Future<bool> clearSave() async {
    try {
      final prefs = await SharedPreferences.getInstance();
      await prefs.remove(_saveKey);
      await prefs.setBool(_hasSaveKey, false);
      // 保留已解锁结局不清除
      return true;
    } catch (e) {
      return false;
    }
  }

  /// 获取所有已解锁结局 ID 列表
  Future<List<int>> loadUnlockedEndings() async {
    try {
      final prefs = await SharedPreferences.getInstance();
      final endingStr = prefs.getString(_endingsKey);
      if (endingStr == null || endingStr.isEmpty) return [];

      final list = jsonDecode(endingStr) as List<dynamic>;
      return list.cast<int>();
    } catch (e) {
      return [];
    }
  }

  /// 保存已解锁结局列表
  Future<bool> saveUnlockedEndings(List<int> endingIds) async {
    try {
      final prefs = await SharedPreferences.getInstance();
      await prefs.setString(_endingsKey, jsonEncode(endingIds));
      return true;
    } catch (e) {
      return false;
    }
  }
}
