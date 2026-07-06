# qcdot Editor - Qt6 graphical node editor library
add_library(qcdot_editor STATIC
    include/qcdot/PortWidget.h
    include/qcdot/ConnectionWidget.h
    include/qcdot/NodeWidget.h
    include/qcdot/EditorScene.h
    include/qcdot/NodeEditor.h
    include/qcdot/Translator.h
    include/qcdot/ThemeManager.h
    include/qcdot/NodePickerDialog.h
    include/qcdot/InlineNodePicker.h
    src/PortWidget.cpp
    src/ConnectionWidget.cpp
    src/NodeWidget.cpp
    src/EditorScene.cpp
    src/NodeEditor.cpp
    src/Translator.cpp
    src/ThemeManager.cpp
    src/NodePickerDialog.cpp
)

target_include_directories(qcdot_editor PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(qcdot_editor PUBLIC
    qcdot_engine
    qcdot_nodes
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
