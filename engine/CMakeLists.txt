# qcdot Engine - Header-only core library
add_library(qcdot_engine INTERFACE)

target_include_directories(qcdot_engine INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(qcdot_engine INTERFACE
    Qt6::Core
    Qt6::Gui
)
