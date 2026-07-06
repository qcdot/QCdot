# QCdot

![Static Badge](https://img.shields.io/badge/License-LGPL2.1-green)
![Static Badge](https://img.shields.io/badge/Version-0.2.0-blue)

[中文版本](README_zh.md) | [Usage Guide](USAGE.md)

A powerful visual programming engine and editor built with Qt6, featuring a node-based interface for dataflow programming.

## Features

- **Visual Programming**: Drag-and-drop node creation with intuitive canvas interface
- **Dual Execution Modes**: Dataflow and Signal-based execution
- **Rich Node Library**: 50+ built-in nodes covering math, logic, data, string, file I/O, containers, and Qt UI
- **Theme Support**: Dark and light themes with complete UI coverage
- **Internationalization**: Chinese/English bilingual UI
- **Cross-platform**: Windows, macOS, Linux (Qt6-based)

## Project Structure

```
qcdot/
├── engine/      # Core engine (Node, Port, Connection, Execution)
├── editor/      # Visual editor (Widgets, Scene, ThemeManager)
├── nodes/       # Built-in node implementations
├── examples/    # Example applications (QCdot-editor)
└── tests/       # Unit tests
```

## Requirements

- Qt 6.5+ (Core, Gui, Widgets)
- CMake 3.20+
- C++17 compiler
- Ninja build system (recommended)

## Building

```bash
# Create build directory
mkdir build && cd build

# Configure with CMake
cmake .. -G Ninja

# Build
ninja
```

## Running

```bash
# Run the example editor
./examples/QCdot-editor/QCdot-editor
```

## Quick Example

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

See [USAGE.md](USAGE.md) for the complete guide.

## License

GNU Lesser General Public License v2.1 (LGPL-2.1)

Copyright © 2026. All rights reserved.
