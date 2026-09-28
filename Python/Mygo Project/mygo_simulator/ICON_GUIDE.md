# 🖼️ 更改程序图标指南

## 目录
- [Android 图标](#android-图标)
- [Windows 图标](#windows-图标)
- [自动生成工具（推荐）](#自动生成工具推荐)

---

## Android 图标

### 图标文件位置

Android 启动图标存放在：

```
mygo_simulator/android/app/src/main/res/
├── mipmap-mdpi/          (48×48)
├── mipmap-hdpi/          (72×72)
├── mipmap-xhdpi/         (96×96)
├── mipmap-xxhdpi/        (144×144)
├── mipmap-xxxhdpi/       (192×192)
└── mipmap-anydpi-v26/    (自适应图标)
```

每个目录下默认有 `ic_launcher.png`。

### 手动替换步骤

1. 准备一张 **1024×1024** 的 PNG 图片作为源文件
2. 用图片工具缩放到各密度尺寸：
   - mdpi: 48×48
   - hdpi: 72×72
   - xhdpi: 96×96
   - xxhdpi: 144×144
   - xxxhdpi: 192×192
3. 将缩放后的图片分别覆盖到对应目录的 `ic_launcher.png`

### 使用 flutter_launcher_icons（推荐）

在 `pubspec.yaml` 中添加配置，一键生成所有尺寸：

```yaml
dev_dependencies:
  flutter_launcher_icons: ^0.14.1

flutter_launcher_icons:
  android: true
  ios: false
  image_path: "assets/icon/app_icon.png"  # 你的源图标路径（1024×1024 PNG）
  adaptive_icon_background: "#0D0221"     # Android 自适应图标背景色
  adaptive_icon_foreground: "assets/icon/app_icon_foreground.png"  # 前景层（可选）
  min_sdk_android: 21
```

然后运行：

```bash
flutter pub get
dart run flutter_launcher_icons
```

所有 Android 密度图标将自动生成并覆盖到 `mipmap-*` 目录。

> ⚠️ 注意：`image_path` 指向的源文件必须放在 `assets/icon/` 目录下（需自行创建），且需要在 `pubspec.yaml` 的 `assets:` 中声明。

---

## Windows 图标

### 图标文件位置

```
mygo_simulator/windows/runner/resources/
└── app_icon.ico
```

### 准备步骤

1. 准备一张 **256×256** 的 PNG 图片
2. 使用在线工具或 ImageMagick 转换为 **ICO** 格式

### 方法一：在线转换

访问 [icoconverter.com](https://www.icoconverter.com/) 或类似站点：
1. 上传 256×256 PNG
2. 选择生成 ICO 格式（包含 256/48/32/16 多尺寸）
3. 下载 `app_icon.ico`
4. 覆盖到 `windows/runner/resources/app_icon.ico`

### 方法二：ImageMagick 命令行

```bash
# 安装 ImageMagick 后：
magick convert app_icon.png -define icon:auto-resize=256,48,32,16 app_icon.ico
```

### 方法三：使用 flutter_launcher_icons（同时生成）

在 `pubspec.yaml` 中增加 Windows 配置：

```yaml
flutter_launcher_icons:
  android: true
  windows: true           # 启用 Windows 图标生成
  ios: false
  image_path: "assets/icon/app_icon.png"
  windows:
    icon_size: 256        # Windows 图标基准尺寸
```

运行后同样会自动覆盖 `windows/runner/resources/app_icon.ico`。

---

## 验证图标生效

### Android

```bash
flutter build apk --release
# 安装后查看桌面图标
```

### Windows

```bash
flutter build windows --release
# 运行 build/windows/x64/runner/Release/mygo_simulator.exe
# 查看任务栏和文件资源管理器中显示的图标
```

---

## 推荐工作流（一条命令完成）

```yaml
# pubspec.yaml 添加：
dev_dependencies:
  flutter_launcher_icons: ^0.14.1

flutter_launcher_icons:
  android: true
  windows: true
  ios: false
  image_path: "assets/icon/app_icon.png"
  adaptive_icon_background: "#0D0221"
  min_sdk_android: 21
```

```bash
# 1. 将 1024×1024 PNG 放到 assets/icon/app_icon.png
# 2. 运行：
flutter pub get
dart run flutter_launcher_icons

# 3. 构建：
flutter build apk --release
flutter build windows --release
```

> 💡 提示：`flutter_launcher_icons` 会自动生成各平台所需的所有尺寸，无需手动处理。
