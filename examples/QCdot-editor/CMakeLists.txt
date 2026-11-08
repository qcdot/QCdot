# QCdot-editor Example - Visual programming editor application
# 移除 EntryPoint，仅保留原有组件
find_package(Qt6 6.5 REQUIRED COMPONENTS Core Gui Widgets)

# WIN32 GUI 程序，加 WIN32 标识
add_executable(QCdot-editor WIN32 main.cpp NodePalette.h ConsoleWidget.h ConsoleRedirector.h)

if(WIN32 AND MINGW)
    # 关键1：开启自动导入，解决 __imp_ 符号缺失
    target_link_options(QCdot-editor PRIVATE
        -Wl,--enable-auto-import
        -Wl,--subsystem,windows
    )
    # 关键2：主动链接mingw CRT库，放在所有Qt库之后
    target_link_libraries(QCdot-editor PRIVATE mingw32 mpr userenv)
endif()

target_link_libraries(QCdot-editor PRIVATE
    qcdot_editor
    qcdot_engine
    qcdot_nodes
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    # mingw32 移到此处（MINGW分支内已单独链接，这里不用重复）
)

# Set output name for the executable
set_target_properties(QCdot-editor PROPERTIES OUTPUT_NAME "QCdot-editor")

# Deploy Qt dependencies automatically after build
if(WIN32)
    find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${Qt6_DIR}/../../../bin")
    if(WINDEPLOYQT_EXECUTABLE)
        add_custom_command(TARGET QCdot-editor POST_BUILD
            COMMAND "${WINDEPLOYQT_EXECUTABLE}"
                --no-compiler-runtime
                --no-translations
                --no-system-d3d-compiler
                --no-opengl-sw
                "$<TARGET_FILE:QCdot-editor>"
            COMMENT "Deploying Qt dependencies..."
        )
    endif()
endif()