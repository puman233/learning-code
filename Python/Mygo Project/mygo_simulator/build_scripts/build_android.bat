@echo off
chcp 65001 >nul
title MyGO Simulator - Android Build

:: ============================================
:: MyGO 剧情决策模拟器 - Android 构建脚本
:: 执行 flutter build apk --split-per-abi 生成 APK
:: ============================================

echo ============================================
echo  MyGO 剧情决策模拟器 - Android 构建
echo ============================================
echo.

:: 切换到项目根目录
cd /d "%~dp0.."

:: 检查 Flutter 是否安装
where flutter >nul 2>&1
if %ERRORLEVEL% neq 0 (
    echo [错误] 未检测到 Flutter SDK，请先安装 Flutter。
    echo 下载地址: https://docs.flutter.dev/get-started/install/windows
    pause
    exit /b 1
)

echo [1/4] 获取依赖包...
call flutter pub get
if %ERRORLEVEL% neq 0 (
    echo [错误] flutter pub get 失败！
    pause
    exit /b 1
)

echo.
echo [2/4] 检查 Android 构建环境...
call flutter doctor --android-licenses >nul 2>&1

echo.
echo [3/4] 构建 Android APK（按 ABI 分割）...
call flutter build apk --split-per-abi --release
if %ERRORLEVEL% neq 0 (
    echo [错误] Android APK 构建失败！
    echo.
    echo 可能的原因：
    echo   - 未安装 Android SDK
    echo   - 未配置 ANDROID_HOME 环境变量
    echo   - JDK 版本不兼容
    pause
    exit /b 1
)

echo.
echo [4/4] 构建完成！
echo.
echo 输出路径:
echo   ARM64:  build\app\outputs\flutter-apk\app-arm64-v8a-release.apk
echo   ARM32:  build\app\outputs\flutter-apk\armeabi-v7a-release.apk
echo   x86_64: build\app\outputs\flutter-apk\x86_64-release.apk
echo.

:: 打开输出目录
start "" "build\app\outputs\flutter-apk\"

echo 构建成功！正在打开输出目录...
pause
