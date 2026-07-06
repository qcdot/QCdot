# QCdot

![Static Badge](https://img.shields.io/badge/License-LGPL2.1-green)
![Static Badge](https://img.shields.io/badge/Version-0.2.0-blue)

[English Version](README.md) | [使用指南](USAGE_zh.md)

一个基于 Qt6 构建的强大可视化编程引擎和编辑器，采用节点式界面进行数据流编程。

## 功能特性

- **可视化编程**：拖放式节点创建，直观的画布界面
- **双执行模式**：数据流和信号两种执行模式
- **丰富节点库**：50+ 内置节点，覆盖数学、逻辑、数据、字符串、文件 I/O、容器和 Qt UI
- **主题支持**：深色和浅色主题，覆盖完整 UI
- **国际化**：中英双语界面
- **跨平台**：Windows、macOS、Linux（基于 Qt6）

## 项目结构

```
qcdot/
├── engine/      # 核心引擎（节点、端口、连接、执行）
├── editor/      # 可视化编辑器（控件、场景、主题管理）
├── nodes/       # 内置节点实现
├── examples/    # 示例应用（QCdot-editor）
└── tests/       # 单元测试
```

## 环境要求

- Qt 6.5+（Core、Gui、Widgets）
- CMake 3.20+
- C++17 编译器
- Ninja 构建系统（推荐）

## 构建步骤

```bash
# 创建构建目录
mkdir build && cd build

# 使用 CMake 配置
cmake .. -G Ninja

# 构建
ninja
```

## 运行

```bash
# 运行示例编辑器
./examples/QCdot-editor/QCdot-editor
```

## 快速示例

```cpp
#include <qcdot/NodeEditor.h>
#include <qcdot/BuiltinNodes.h>
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    qcdot::NodeEditor editor;
    auto* intNode = editor.addNode("ConstantInt", 100, 100);
    auto* addNode = editor.addNode("Add", 300, 100);

    editor.graph()->connect(
        intNode->outputs()[0].get(),
        addNode->inputs()[0].get()
    );

    editor.show();
    return app.exec();
}
```

完整指南请参见 [USAGE_zh.md](USAGE_zh.md)。

## 许可证

GNU Lesser General Public License v2.1（LGPL-2.1）

Copyright © 2026. All rights reserved.
