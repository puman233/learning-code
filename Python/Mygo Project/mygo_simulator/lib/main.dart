import 'package:flutter/material.dart';
import 'app/mygo_app.dart';

/// MyGO 剧情决策模拟器 - 主入口
///
/// 基于《BanG Dream! It's MyGO!!!!!》剧情改编的视觉小说式决策模拟器。
/// 纯 Flutter 实现，零 Python 后端依赖，JSON 数据驱动。
///
/// 核心特性：
/// - 状态机驱动的剧情流程引擎
/// - 视觉小说风格 UI（逐字打印、毛玻璃对话框、角色头像）
/// - 多分支决策系统（2个核心判断节点 -> 3种结局）
/// - 动态流程图地图（InteractiveViewer + CustomPaint 贝塞尔曲线）
/// - 多结局收集系统（SharedPreferences 持久化）
/// - 自动存档与进度恢复
void main() {
  WidgetsFlutterBinding.ensureInitialized();
  runApp(const MygoApp());
}
