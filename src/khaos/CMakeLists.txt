add_library(Headers INTERFACE)

configure_file("${PROJECT_SOURCE_DIR}/include/khaos/KhaosVersion.h.in" "${PROJECT_BINARY_DIR}/include/khaos/KhaosVersion.h" @ONLY)
target_include_directories(Headers INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include> $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include> $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
add_library(Khaos::Headers ALIAS Headers)
