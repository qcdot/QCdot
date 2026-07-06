# qcdot Builtin Nodes - Header-only library
add_library(qcdot_nodes INTERFACE)

target_include_directories(qcdot_nodes INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(qcdot_nodes INTERFACE
    qcdot_engine
)
