# QCdot Usage Guide

**Version**: 0.2.0

[中文版本](USAGE_zh.md)

## Overview

QCdot is a visual programming engine that allows you to create node-based applications. It consists of two main components:

1. **Engine**: Core library for node graph manipulation and execution
2. **Editor**: Visual components for building node-based UIs

## Getting Started

### Basic Setup

```cpp
#include <qcdot/NodeEditor.h>
#include <qcdot/BuiltinNodes.h>
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // Create the node editor
    qcdot::NodeEditor editor;

    // Add nodes
    auto* intNode = editor.addNode("ConstantInt", 100, 100);
    auto* addNode = editor.addNode("Add", 300, 100);

    // Connect nodes
    editor.graph()->connect(
        intNode->outputs()[0].get(),
        addNode->inputs()[0].get()
    );

    editor.show();
    return app.exec();
}
```

## Node Types

### Math Nodes
- `Add` - Integer/Float addition
- `Subtract` - Integer/Float subtraction
- `Multiply` - Integer/Float multiplication
- `Divide` - Integer/Float division
- `Modulo` - Integer modulo
- `Power` - Exponentiation
- `Sqrt` - Square root

### Logic Nodes
- `Equal` - Equality comparison
- `GreaterThan` - Greater than comparison
- `LessThan` - Less than comparison
- `And` - Logical AND
- `Or` - Logical OR
- `Not` - Logical NOT
- `IfElse` - Conditional branching
- `IfElseBranch` - Multi-branch conditional

### Control Flow Nodes
- `InputBlock` - Graph entry point
- `EventBlock` - Event-driven entry point

### Data Nodes
- `ConstantInt` - Integer constant (use `setValue(int64_t)`)
- `ConstantFloat` - Float constant (use `setValue(double)`)
- `ConstantBool` - Boolean constant (use `setValue(bool)`)
- `ConstantString` - String constant (use `setValue(const std::string&)`)
- `Variable` - Variable storage
- `Counter` - Counter with increment

### Conversion Nodes
- `IntToFloat` - Convert integer to float
- `FloatToInt` - Convert float to integer
- `ToString` - Convert value to string

### String Nodes
- `StringConcat` - Concatenate strings
- `StringLength` - Get string length
- `StringSubstring` - Extract substring

### Bitwise Nodes
- `BinaryAnd` - Bitwise AND
- `BinaryOr` - Bitwise OR
- `BinaryXor` - Bitwise XOR
- `ShiftLeft` - Left shift
- `ShiftRight` - Right shift

### File Nodes
- `FileReadText` - Read text file
- `FileWriteText` - Write text file
- `FileReadBinary` - Read binary file

### Utility Nodes
- `RandomInt` - Generate random integer
- `Sleep` - Pause execution
- `Sort` - Sort a vector
- `Void` - No-op / discard value

### Container Nodes
- `StdVector` / `StdVectorPush` - `std::vector` operations
- `StdQueue` / `StdQueuePush` - `std::queue` operations
- `StdStack` / `StdStackPush` - `std::stack` operations
- `StdDeque` / `StdDequePush` - `std::deque` operations
- `StdSet` / `StdSetInsert` - `std::set` operations
- `StdUnorderedSet` / `StdUnorderedSetInsert` - `std::unordered_set` operations
- `StdPair` - `std::pair` constructor
- `Struct` - User-defined struct

### Qt UI Nodes
- `Color` - RGBA color value
- `QtMainWindow` - Top-level window container
- `QtButton` - Clickable button
- `QtLabel` - Text display label
- `QtLineEdit` - Single-line text input
- `QtTabWidget` - Tab container
- `QtLayout` - Layout container
- `QtSlider` - Value slider
- `QtCheckBox` - Checkbox
- `QtComboBox` - Dropdown selection
- `QtSpinBox` - Numeric spin box
- `QtProgressBar` - Progress indicator

## Setting Constant Values

```cpp
// Integer constants
auto* intNode = editor.addNode("ConstantInt", 80, 60);
if (auto* constNode = dynamic_cast<qcdot::Builtin::ConstantIntNode*>(intNode))
    constNode->setValue(42);

// Float constants
auto* floatNode = editor.addNode("ConstantFloat", 80, 160);
if (auto* constNode = dynamic_cast<qcdot::Builtin::ConstantFloatNode*>(floatNode))
    constNode->setValue(3.14159);

// Boolean constants
auto* boolNode = editor.addNode("ConstantBool", 80, 260);
if (auto* constNode = dynamic_cast<qcdot::Builtin::ConstantBoolNode*>(boolNode))
    constNode->setValue(true);

// String constants
auto* strNode = editor.addNode("ConstantString", 80, 360);
if (auto* constNode = dynamic_cast<qcdot::Builtin::ConstantStringNode*>(strNode))
    constNode->setValue("Hello World");
```

## Theme Management

```cpp
#include <qcdot/ThemeManager.h>

// Get current theme
auto theme = qcdot::ThemeManager::instance().currentTheme();

// Switch to dark mode
qcdot::ThemeManager::instance().setTheme(qcdot::ThemeMode::Dark);

// Switch to light mode
qcdot::ThemeManager::instance().setTheme(qcdot::ThemeMode::Light);

// Listen for theme changes
qcdot::ThemeManager::onThemeChanged([]() {
    // Update your UI
});
```

## Language Management

```cpp
#include <qcdot/Translator.h>

// Set language to Chinese
qcdot::Translator::setLanguage("zh");

// Set language to English
qcdot::Translator::setLanguage("en");

// Get translated string
QString title = qcdot::Translator::tr("app.title");
```

## Saving and Loading

```cpp
// Save graph to file
editor.saveToFile("my_graph.qcd");

// Load graph from file
editor.loadFromFile("my_graph.qcd");
```

## Custom Nodes

To create custom nodes, inherit from `qcdot::Node`:

```cpp
class MyCustomNode : public qcdot::Node {
public:
    MyCustomNode() {
        addInput("input", qcdot::DataType::Integer);
        addOutput("output", qcdot::DataType::Integer);
    }

    std::string typeName() const override { return "MyCustomNode"; }
    std::string nodeTitle() const override { return "My Custom Node"; }

    void process(const qcdot::VariantMap& in, qcdot::VariantMap& out) override {
        int value = in.at("input").toInt();
        out["output"] = qcdot::Variant(value * 2);
    }
};
```

Register the custom node using the node factory.

## Editor Features

### Drag and Drop
- Drag nodes from the palette to the canvas
- Drag connections between ports
- Click and drag nodes to reposition

### Keyboard Shortcuts
- Delete node: Select node and press Delete
- Copy node: Ctrl+C
- Paste node: Ctrl+V

### Context Menu
- Right-click on canvas to show node picker
- Double-click on constant nodes to edit values
