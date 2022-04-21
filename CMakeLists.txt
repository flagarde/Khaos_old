cmake_minimum_required(VERSION 3.16)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(GetCMakeMM)
cmmm(VERSION 2.2 REPOSITORY flagarde/CMakeMM)

cmmm_modules_list(REPOSITORY flagarde/CMakeCM)

project(Khaos VERSION 0.0.1.0 DESCRIPTION "A C/C++ library to simplify cross-platform programming" HOMEPAGE_URL "https://github.com/flagarde/Khaos" LANGUAGES C CXX)

include(PreventInSourceBuilds)
prevent_in_source_builds()

include(DefaultInstallPrefix)
default_install_prefix("${CMAKE_SOURCE_DIR}/install")

option(BUILD_DOCS "Build the docs" ON)
option(BUILD_TESTS "Build the tests" ON)

add_subdirectory(src)

if(BUILD_DOCS)
  add_subdirectory(docs)
endif()

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
