cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

option(KHAOS_BUILD_DOCS "Build the docs" ON)
option(KHAOS_BUILD_TESTS "Build the tests" ON)
option(KHAOS_BUILD_EXAMPLES "Build the examples" ON)

if(KHAOS_BUILD_DOCS OR KHAOS_BUILD_TESTS AND ("${CMAKE_VERSION}" VERSION_GREATER "3.10.3"))
  include(FetchContent)
  FetchContent_Declare(CMMM GIT_REPOSITORY "https://github.com/cmake-tools/cmmm.git" GIT_TAG "v1.0")
  FetchContent_MakeAvailable(CMMM)
  cmmm()
  cmmm_modules_list(URL "gh:flagarde/CMakeCM#main" FILEPATH ModulesListNew.cmake)
endif()

if("${CMAKE_VERSION}" VERSION_GREATER "3.11.4")
  project(Khaos VERSION 0.0.1.0 DESCRIPTION "A C/C++ library to simplify cross-platform programming" HOMEPAGE_URL "https://github.com/flagarde/Khaos" LANGUAGES C CXX)
elseif("${CMAKE_VERSION}" VERSION_GREATER "3.8.2")
  project(Khaos VERSION 0.0.1.0 DESCRIPTION "A C/C++ library to simplify cross-platform programming" LANGUAGES C CXX)
else()
  project(Khaos VERSION 0.0.1.0 LANGUAGES C CXX)
endif()

add_subdirectory(src)

if(KHAOS_BUILD_DOCS)
  add_subdirectory(docs)
endif()

if(KHAOS_BUILD_TESTS)
  include(CTest)
  add_subdirectory(tests)
endif()

if(KHAOS_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()
