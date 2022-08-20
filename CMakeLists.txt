cmake_minimum_required(VERSION 3.16)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

option(BUILD_DOCS "Build the docs" ON)
option(BUILD_TESTS "Build the tests" ON)

if(BUILD_DOCS OR BUILD_TESTS)
  include(GetCMakeMM)
  cmmm(VERSION 2.3 REPOSITORY flagarde/CMakeMM)

  cmmm_modules_list(REPOSITORY flagarde/CMakeCM)
endif()

project(Khaos VERSION 0.0.1.0 DESCRIPTION "A C/C++ library to simplify cross-platform programming" HOMEPAGE_URL "https://github.com/flagarde/Khaos" LANGUAGES C CXX)

add_subdirectory(src)

if(BUILD_DOCS)
  add_subdirectory(docs)
endif()

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
