# QCdot 使用指南

**版本**：0.2.0

[English Version](USAGE.md)

## 概述

QCdot 是一个可视化编程引擎，允许您创建基于节点的应用程序。它包含两个主要组件：

1. **引擎**：用于节点图操作和执行的核心库
2. **编辑器**：用于构建节点式用户界面的可视化组件

## 快速开始

### 基本设置

```cpp
#include <qcdot/NodeEditor.h>
#include <qcdot/BuiltinNodes.h>
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // 创建节点编辑器
    qcdot::NodeEditor editor;

    // 添加节点
    auto* intNode = editor.addNode("ConstantInt", 100, 100);
    auto* addNode = editor.addNode("Add", 300, 100);

    // 连接节点
    editor.graph()->connect(
        intNode->outputs()[0].get(),
        addNode->inputs()[0].get()
    );

    editor.show();
    return app.exec();
}
```

## 节点类型

### 数学节点
- `Add` - 整数/浮点数加法
- `Subtract` - 整数/浮点数减法
- `Multiply` - 整数/浮点数乘法
- `Divide` - 整数/浮点数除法
- `Modulo` - 整数取模
- `Power` - 幂运算
- `Sqrt` - 平方根

### 逻辑节点
- `Equal` - 相等比较
- `GreaterThan` - 大于比较
- `LessThan` - 小于比较
- `And` - 逻辑与
- `Or` - 逻辑或
- `Not` - 逻辑非
- `IfElse` - 条件分支
- `IfElseBranch` - 多路条件分支

### 控制流节点
- `InputBlock` - 图入口点
- `EventBlock` - 事件驱动入口点

### 数据节点
- `ConstantInt` - 整数常量（使用 `setValue(int64_t)`）
- `ConstantFloat` - 浮点数常量（使用 `setValue(double)`）
- `ConstantBool` - 布尔常量（使用 `setValue(bool)`）
- `ConstantString` - 字符串常量（使用 `setValue(const std::string&)`）
- `Variable` - 变量存储
- `Counter` - 计数器

### 转换节点
- `IntToFloat` - 整数转浮点数
- `FloatToInt` - 浮点数转整数
- `ToString` - 转字符串

### 字符串节点
- `StringConcat` - 字符串拼接
- `StringLength` - 获取字符串长度
- `StringSubstring` - 提取子串

### 位运算节点
- `BinaryAnd` - 按位与
- `BinaryOr` - 按位或
- `BinaryXor` - 按位异或
- `ShiftLeft` - 左移
- `ShiftRight` - 右移

### 文件节点
- `FileReadText` - 读取文本文件
- `FileWriteText` - 写入文本文件
- `FileReadBinary` - 读取二进制文件

### 工具节点
- `RandomInt` - 生成随机整数
- `Sleep` - 暂停执行
- `Sort` - 对向量排序
- `Void` - 空操作 / 丢弃值

### 容器节点
- `StdVector` / `StdVectorPush` - `std::vector` 操作
- `StdQueue` / `StdQueuePush` - `std::queue` 操作
- `StdStack` / `StdStackPush` - `std::stack` 操作
- `StdDeque` / `StdDequePush` - `std::deque` 操作
- `StdSet` / `StdSetInsert` - `std::set` 操作
- `StdUnorderedSet` / `StdUnorderedSetInsert` - `std::unordered_set` 操作
- `StdPair` - `std::pair` 构造器
- `Struct` - 用户自定义结构体

### Qt UI 节点
- `Color` - RGBA 颜色值
- `QtMainWindow` - 顶级窗口容器
- `QtButton` - 可点击按钮
- `QtLabel` - 文本显示标签
- `QtLineEdit` - 单行文本输入
- `QtTabWidget` - 标签页容器
- `QtLayout` - 布局容器
- `QtSlider` - 数值滑块
- `QtCheckBox` - 复选框
- `QtComboBox` - 下拉选择
- `QtSpinBox` - 数值输入框
- `QtProgressBar` - 进度指示器

## 设置常量值

```cpp
// 整数常量
auto* intNode = editor.addNode("ConstantInt", 80, 60);
if (auto* constNode = dynamic_cast<qcdot::Builtin::ConstantIntNode*>(intNode))
    constNode->setValue(42);

// 浮点数常量
auto* floatNode = editor.addNode("ConstantFloat", 80, 160);
if (auto* constNode = dynamic_cast<qcdot::Builtin::ConstantFloatNode*>(floatNode))
    constNode->setValue(3.14159);

// 布尔常量
auto* boolNode = editor.addNode("ConstantBool", 80, 260);
if (auto* constNode = dynamic_cast<qcdot::Builtin::ConstantBoolNode*>(boolNode))
    constNode->setValue(true);

// 字符串常量
auto* strNode = editor.addNode("ConstantString", 80, 360);
if (auto* constNode = dynamic_cast<qcdot::Builtin::ConstantStringNode*>(strNode))
    constNode->setValue("Hello World");
```

## 主题管理

```cpp
#include <qcdot/ThemeManager.h>

// 获取当前主题
auto theme = qcdot::ThemeManager::instance().currentTheme();

// 切换到深色模式
qcdot::ThemeManager::instance().setTheme(qcdot::ThemeMode::Dark);

// 切换到浅色模式
qcdot::ThemeManager::instance().setTheme(qcdot::ThemeMode::Light);

// 监听主题变化
qcdot::ThemeManager::onThemeChanged([]() {
    // 更新您的 UI
});
```

## 语言管理

```cpp
#include <qcdot/Translator.h>

// 设置语言为中文
qcdot::Translator::setLanguage("zh");

// 设置语言为英文
qcdot::Translator::setLanguage("en");

// 获取翻译字符串
QString title = qcdot::Translator::tr("app.title");
```

## 保存和加载

```cpp
// 保存图到文件
editor.saveToFile("my_graph.qcd");

// 从文件加载图
editor.loadFromFile("my_graph.qcd");
```

## 自定义节点

创建自定义节点，继承自 `qcdot::Node`：

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

使用节点工厂注册自定义节点。

## 编辑器功能

### 拖放操作
- 从素材库拖放节点到画布
- 在端口之间拖放连接线
- 点击并拖动节点重新定位

### 快捷键
- 删除节点：选中节点后按 Delete
- 复制节点：Ctrl+C
- 粘贴节点：Ctrl+V

### 上下文菜单
- 在画布上右键显示节点选择器
- 双击常量节点编辑值
