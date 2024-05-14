message(STATUS "CMAKE_CXX_COMPILER_ID : ${CMAKE_CXX_COMPILER_ID} CMAKE_CXX_COMPILER_FRONTEND_VARIANT : ${CMAKE_CXX_COMPILER_FRONTEND_VARIANT}")

list(FIND CMAKE_CXX_COMPILE_FEATURES cxx_std_11 CPP_STANDARD_FOUND)
if(CPP_STANDARD_FOUND STREQUAL "-1" OR ((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") AND ${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 4.8))
  include(Missives)
  missive(ERROR "Compiler ${CMAKE_CXX_COMPILER_ID} is too old to run doctest")
  missive(ERROR "Tests disabled")
  return()
else()
  set(doctest_DOCTEST_NO_INSTALL TRUE)
  include(Doctest)
endif()

if(POLICY CMP0110)
  cmake_policy(SET CMP0110 NEW)
endif()

add_library(KhaosTestFlags INTERFACE)

target_compile_options(KhaosTestFlags INTERFACE
  $<$<CXX_COMPILER_ID:Clang>:-Wall -Weverything -pedantic>
  $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -pedantic>
  $<$<CXX_COMPILER_ID:Intel>:-Wall -Wextra -pedantic>
  $<$<CXX_COMPILER_ID:IntelLLVM>:-Wall -Wextra -pedantic>
  $<$<CXX_COMPILER_ID:MSVC>:/W4>
  $<$<C_COMPILER_ID:Clang>:-Wall -Weverything -pedantic>
  $<$<C_COMPILER_ID:GNU>:-Wall -Wextra -pedantic>
  $<$<C_COMPILER_ID:IntelLLVM>:-Wall -Wextra -pedantic>
  $<$<C_COMPILER_ID:Intel>:-Wall -Wextra -pedantic>
  $<$<C_COMPILER_ID:MSVC>:/W4>)

add_executable(KhaosVersion.test KhaosVersion.test.cpp)
target_link_libraries(KhaosVersion.test PRIVATE Khaos::Khaos doctest_with_main KhaosTestFlags)
target_compile_definitions(KhaosVersion.test PRIVATE "-DMAJOR=${Khaos_VERSION_MAJOR}" "-DMINOR=${Khaos_VERSION_MINOR}" "-DPATCH=${Khaos_VERSION_PATCH}" "-DTWEAK=${Khaos_VERSION_TWEAK}")
doctest_discover_tests(KhaosVersion.test)

add_executable(Version.test Version.test.cpp)
target_link_libraries(Version.test PRIVATE Khaos::Khaos doctest_with_main KhaosTestFlags)
target_compile_definitions(Version.test PRIVATE "-DMAJOR=${Khaos_VERSION_MAJOR}" "-DMINOR=${Khaos_VERSION_MINOR}" "-DPATCH=${Khaos_VERSION_PATCH}" "-DTWEAK=${Khaos_VERSION_TWEAK}")
doctest_discover_tests(Version.test)

add_executable(CompareVersion.test CompareVersion.test.cpp)
target_link_libraries(CompareVersion.test PRIVATE Khaos::Khaos doctest_with_main KhaosTestFlags)
target_compile_definitions(CompareVersion.test PRIVATE "-DMAJOR=${Khaos_VERSION_MAJOR}" "-DMINOR=${Khaos_VERSION_MINOR}" "-DPATCH=${Khaos_VERSION_PATCH}" "-DTWEAK=${Khaos_VERSION_TWEAK}")
doctest_discover_tests(CompareVersion.test)

add_executable(CStandards.test CStandards.test.cpp)
target_link_libraries(CStandards.test PRIVATE Khaos::Khaos doctest_with_main KhaosTestFlags)
doctest_discover_tests(CStandards.test)

add_executable(CXXStandards.test CXXStandards.test.cpp)
target_link_libraries(CXXStandards.test PRIVATE Khaos::Khaos doctest_with_main KhaosTestFlags)
doctest_discover_tests(CXXStandards.test)

set(CXX_STANDARDS)
foreach(FEATURE IN LISTS CMAKE_CXX_COMPILE_FEATURES)
  string(REGEX MATCH "cxx_std_[0-9]+" cxx_std "${FEATURE}")
  if(NOT "${cxx_std}" STREQUAL "")
    list(APPEND CXX_STANDARDS "${cxx_std}")
  endif()
endforeach()
list(POP_BACK CXX_STANDARDS)
set(C_STANDARDS)
foreach(FEATURE IN LISTS CMAKE_C_COMPILE_FEATURES)
  string(REGEX MATCH "c_std_[0-9]+" c_std "${FEATURE}")
  if(NOT "${c_std}" STREQUAL "")
    list(APPEND C_STANDARDS "${c_std}")
  endif()
endforeach()
list(POP_BACK C_STANDARDS)

message(STATUS "Compiler support CXX :${CXX_STANDARDS}")
message(STATUS "Compiler support C : ${C_STANDARDS}")
if(MSVC)
  set(CXX_EXTENSIONS "ON")
  list(REMOVE_ITEM CXX_STANDARDS "cxx_std_98" "cxx_std_11") #MSVC has no c++98 c++11 options
else()
  set(CXX_EXTENSIONS "ON;OFF")
endif()
foreach(CXX_STANDARD IN LISTS CXX_STANDARDS)
  string(REPLACE "cxx_std_" "" CXX_STANDARD_NUMBER "${CXX_STANDARD}")
  foreach(CXX_EXTENSION IN LISTS CXX_EXTENSIONS)
    add_executable("Language_${CXX_STANDARD}_extensions_${CXX_EXTENSION}.test" LanguageCXX.test.cpp)
    if("${CXX_EXTENSION}" STREQUAL ON)
      target_compile_definitions("Language_${CXX_STANDARD}_extensions_${CXX_EXTENSION}.test" PRIVATE "-DCPP_STANDARD=${CXX_STANDARD_NUMBER}" "-DCPP_EXTENSIONS=1")
    else()
      target_compile_definitions("Language_${CXX_STANDARD}_extensions_${CXX_EXTENSION}.test" PRIVATE "-DCPP_STANDARD=${CXX_STANDARD_NUMBER}" "-DCPP_EXTENSIONS=0")
    endif()
    set_target_properties("Language_${CXX_STANDARD}_extensions_${CXX_EXTENSION}.test" PROPERTIES CXX_STANDARD "${CXX_STANDARD_NUMBER}")
    set_target_properties("Language_${CXX_STANDARD}_extensions_${CXX_EXTENSION}.test" PROPERTIES CXX_STANDARD_REQUIRED TRUE)
    set_target_properties("Language_${CXX_STANDARD}_extensions_${CXX_EXTENSION}.test" PROPERTIES CXX_EXTENSIONS "${CXX_EXTENSION}")
    if("${CXX_STANDARD}" STREQUAL "cxx_std_98")
      target_link_libraries("Language_${CXX_STANDARD}_extensions_${CXX_EXTENSION}.test" PRIVATE Khaos::Khaos KhaosTestFlags)
      add_test(NAME "Test the Language ${CXX_STANDARD} extensions ${CXX_EXTENSION}" COMMAND "Language_${CXX_STANDARD}_extensions_${CXX_EXTENSION}.test")
    else()
      target_link_libraries("Language_${CXX_STANDARD}_extensions_${CXX_EXTENSION}.test" PRIVATE Khaos::Khaos doctest_with_main KhaosTestFlags)
      doctest_discover_tests("Language_${CXX_STANDARD}_extensions_${CXX_EXTENSION}.test")
    endif()
  endforeach()
endforeach()

if(MSVC)
  set(C_EXTENSIONS "ON")
  list(REMOVE_ITEM C_STANDARDS "c_std_99") #MSVC has no c99 option
else()
  set(C_EXTENSIONS "ON;OFF")
endif()
foreach(C_STANDARD IN LISTS C_STANDARDS)
  string(REPLACE "c_std_" "" C_STANDARD_NUMBER "${C_STANDARD}")
  foreach(C_EXTENSION IN LISTS C_EXTENSIONS)
    add_executable("Language_${C_STANDARD}_extensions_${C_EXTENSION}.test" LanguageC.test.c)
    if("${C_EXTENSION}" STREQUAL ON)
      target_compile_definitions("Language_${C_STANDARD}_extensions_${C_EXTENSION}.test" PRIVATE "-DC_STANDARD=${C_STANDARD_NUMBER}" "-DC_EXTENSIONS=1")
    else()
      target_compile_definitions("Language_${C_STANDARD}_extensions_${C_EXTENSION}.test" PRIVATE "-DC_STANDARD=${C_STANDARD_NUMBER}" "-DC_EXTENSIONS=0")
    endif()
    set_target_properties("Language_${C_STANDARD}_extensions_${C_EXTENSION}.test" PROPERTIES C_STANDARD "${C_STANDARD_NUMBER}")
    set_target_properties("Language_${C_STANDARD}_extensions_${C_EXTENSION}.test" PROPERTIES C_STANDARD_REQUIRED TRUE)
    set_target_properties("Language_${C_STANDARD}_extensions_${C_EXTENSION}.test" PROPERTIES C_EXTENSIONS "${C_EXTENSION}")
    target_link_libraries("Language_${C_STANDARD}_extensions_${C_EXTENSION}.test" PRIVATE Khaos::Khaos KhaosTestFlags)
    add_test(NAME "Test the language ${C_STANDARD} extensions ${C_EXTENSION}" COMMAND "Language_${C_STANDARD}_extensions_${C_EXTENSION}.test")
  endforeach()
endforeach()
