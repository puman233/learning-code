@echo off
chcp 65001 >nul
title MyGO Simulator - Windows Build

:: ============================================
:: MyGO 剧情决策模拟器 - Windows 构建脚本
:: 执行 flutter build windows --release 生成 EXE
:: ============================================

echo ============================================
echo  MyGO 剧情决策模拟器 - Windows 构建
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
echo [2/4] 检查 Windows 构建支持...
call flutter config --enable-windows-desktop >nul 2>&1

echo.
echo [3/4] 构建 Windows 发布版...
call flutter build windows --release
if %ERRORLEVEL% neq 0 (
    echo [错误] Windows 构建失败！
    pause
    exit /b 1
)

echo.
echo [4/4] 构建完成！
echo.
echo 输出路径: build\windows\x64\runner\Release\
echo 可执行文件: mygo_simulator.exe
echo.

:: 打开输出目录
start "" "build\windows\x64\runner\Release\"

echo 构建成功！正在打开输出目录...
pause
