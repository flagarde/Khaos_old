cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

option(KHAOS_BUILD_DOCS "Build the docs" ON)
option(KHAOS_BUILD_TESTS "Build the tests" ON)

if(KHAOS_BUILD_DOCS OR KHAOS_BUILD_TESTS)
  include(FetchContent)
  FetchContent_Declare(CMMM GIT_REPOSITORY "https://github.com/cmake-tools/cmmm.git" GIT_TAG "v1.0")
  FetchContent_MakeAvailable(CMMM)
  cmmm()
  cmmm_modules_list(URL "https://raw.githubusercontent.com/flagarde/CMakeCM/main/ModulesList.cmake")
endif()

project(Khaos VERSION 0.0.1.0 DESCRIPTION "A C/C++ library to simplify cross-platform programming" HOMEPAGE_URL "https://github.com/flagarde/Khaos" LANGUAGES C CXX)

add_subdirectory(src)

if(KHAOS_BUILD_DOCS)
  add_subdirectory(docs)
endif()

if(KHAOS_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
