include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

configure_file(KhaosVersion.h.in "${PROJECT_BINARY_DIR}/include/Khaos/KhaosVersion.h" @ONLY)

add_library(Khaos INTERFACE)
set(KHAOS_PUBLIC_HEADERS
    "${PROJECT_BINARY_DIR}/include/Khaos/KhaosVersion.h"
    "${PROJECT_SOURCE_DIR}/include/Khaos/details/languages/C.h"
    "${PROJECT_SOURCE_DIR}/include/Khaos/details/languages/CStandards.h"
    "${PROJECT_SOURCE_DIR}/include/Khaos/details/languages/CXX.h"
    "${PROJECT_SOURCE_DIR}/include/Khaos/details/languages/CXXStandards.h"
    "${PROJECT_SOURCE_DIR}/include/Khaos/details/languages/Extensions.h"
    "${PROJECT_SOURCE_DIR}/include/Khaos/CompareVersions.h"
    "${PROJECT_SOURCE_DIR}/include/Khaos/Compiler.h"
    "${PROJECT_SOURCE_DIR}/include/Khaos/Language.h"
    "${PROJECT_SOURCE_DIR}/include/Khaos/Preprocessor.h"
    "${PROJECT_SOURCE_DIR}/include/Khaos/Version.h")
set_target_properties(Khaos PROPERTIES PUBLIC_HEADER "${KHAOS_PUBLIC_HEADERS}")
target_compile_options(Khaos INTERFACE $<$<AND:$<CXX_COMPILER_ID:Clang>,$<VERSION_LESS:CMAKE_CXX_COMPILER_VERSION,3.6>,$<STREQUAL:${CMAKE_CXX_COMPILER_FRONTEND_VARIANT},GNU>>:-Wno-c++98-compat-pedantic>)
target_include_directories(Khaos INTERFACE "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/>" "$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include/>" "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
install(TARGETS Khaos EXPORT KhaosTargets
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
        INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/Khaos"
        PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/Khaos")
install(EXPORT KhaosTargets FILE KhaosTargets.cmake NAMESPACE Khaos:: DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/Khaos")
export(EXPORT KhaosTargets FILE "${CMAKE_CURRENT_BINARY_DIR}/Khaos/KhaosTargets.cmake" NAMESPACE Khaos::)
add_library(Khaos::Khaos ALIAS Khaos)

write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/KhaosConfigVersion.cmake" COMPATIBILITY SameMajorVersion ARCH_INDEPENDENT)
configure_package_config_file("${PROJECT_SOURCE_DIR}/cmake/KhaosConfig.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/KhaosConfig.cmake" INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/Khaos")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/KhaosConfig.cmake" "${CMAKE_CURRENT_BINARY_DIR}/KhaosConfigVersion.cmake" DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/Khaos")
