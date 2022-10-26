list(FIND CMAKE_CXX_COMPILE_FEATURES cxx_std_11 CPP_STANDARD_FOUND)
if(CPP_STANDARD_FOUND STREQUAL "-1" OR ((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") AND ${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 4.8))
  include(Missives)
  missive(ERROR "Compiler ${CMAKE_CXX_COMPILER_ID} is too old to run doctest")
  missive(ERROR "Tests disabled")
  return()
else()
  include(Doctest)
endif()

if(POLICY CMP0110)
  cmake_policy(SET CMP0110 NEW)
endif()

add_library(KhaosTestFlags INTERFACE)

target_compile_options(KhaosTestFlags INTERFACE
  $<$<CXX_COMPILER_ID:Clang>:-Wall -Weverything -pedantic -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded>
  $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -pedantic>
  $<$<CXX_COMPILER_ID:Intel>:-Wall -Wextra -pedantic>
  $<$<CXX_COMPILER_ID:IntelLLVM>:-Wall -Wextra -pedantic>
  $<$<CXX_COMPILER_ID:MSVC>:/W4>
  $<$<C_COMPILER_ID:Clang>:-Wall -Weverything -pedantic -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded>
  $<$<C_COMPILER_ID:GNU>:-Wall -Wextra -pedantic>
  $<$<C_COMPILER_ID:IntelLLVM>:-Wall -Wextra -pedantic>
  $<$<C_COMPILER_ID:Intel>:-Wall -Wextra -pedantic>
  $<$<C_COMPILER_ID:MSVC>:/W4>)

add_executable(KhaosVersion.test KhaosVersion.test.cpp)
target_link_libraries(KhaosVersion.test PRIVATE Khaos::Headers doctest_with_main KhaosTestFlags)
target_compile_definitions(KhaosVersion.test PRIVATE "-DMAJOR=${Khaos_VERSION_MAJOR}" "-DMINOR=${Khaos_VERSION_MINOR}" "-DPATCH=${Khaos_VERSION_PATCH}" "-DTWEAK=${Khaos_VERSION_TWEAK}")
doctest_discover_tests(KhaosVersion.test)

add_executable(VersionMacros.test VersionMacros.test.cpp)
target_link_libraries(VersionMacros.test PRIVATE Khaos::Headers doctest_with_main KhaosTestFlags)
target_compile_definitions(VersionMacros.test PRIVATE "-DMAJOR=${Khaos_VERSION_MAJOR}" "-DMINOR=${Khaos_VERSION_MINOR}" "-DPATCH=${Khaos_VERSION_PATCH}" "-DTWEAK=${Khaos_VERSION_TWEAK}")
doctest_discover_tests(VersionMacros.test)

add_executable(CompareVersionMacros.test CompareVersionMacros.test.cpp)
target_link_libraries(CompareVersionMacros.test PRIVATE Khaos::Headers doctest_with_main KhaosTestFlags)
target_compile_definitions(CompareVersionMacros.test PRIVATE "-DMAJOR=${Khaos_VERSION_MAJOR}" "-DMINOR=${Khaos_VERSION_MINOR}" "-DPATCH=${Khaos_VERSION_PATCH}" "-DTWEAK=${Khaos_VERSION_TWEAK}")
doctest_discover_tests(CompareVersionMacros.test)

add_executable(CStandards.test CStandards.test.cpp)
target_link_libraries(CStandards.test PRIVATE Khaos::Headers doctest_with_main KhaosTestFlags)
doctest_discover_tests(CStandards.test)

add_executable(CXXStandards.test CXXStandards.test.cpp)
target_link_libraries(CXXStandards.test PRIVATE Khaos::Headers doctest_with_main KhaosTestFlags)
doctest_discover_tests(CXXStandards.test)

set(CPP_STANDARDS "98;11;14;17")
set(CPP_EXTENSIONS "ON;OFF")
foreach(CPP_STANDARD ${CPP_STANDARDS})
  list(FIND CMAKE_CXX_COMPILE_FEATURES cxx_std_${CPP_STANDARD} CPP_STANDARD_FOUND)
  if(NOT CPP_STANDARD_FOUND STREQUAL "-1")
    foreach(CPP_EXTENSION ${CPP_EXTENSIONS})
      add_executable(LanguageCXX${CPP_STANDARD}Extensions${CPP_EXTENSION}.test LanguageCXX.test.cpp)
      if("${CPP_EXTENSION}" STREQUAL ON)
        target_compile_definitions(LanguageCXX${CPP_STANDARD}Extensions${CPP_EXTENSION}.test PRIVATE "-DCPP_STANDARD=${CPP_STANDARD}" "-DCPP_EXTENSIONS=1")
      else()
        target_compile_definitions(LanguageCXX${CPP_STANDARD}Extensions${CPP_EXTENSION}.test PRIVATE "-DCPP_STANDARD=${CPP_STANDARD}" "-DCPP_EXTENSIONS=0")
        if(MSVC)
          target_compile_options(LanguageCXX${CPP_STANDARD}Extensions${CPP_EXTENSION}.test PRIVATE "/permissive-")
        endif()
      endif()
      set_target_properties(LanguageCXX${CPP_STANDARD}Extensions${CPP_EXTENSION}.test PROPERTIES CXX_STANDARD ${CPP_STANDARD})
      set_target_properties(LanguageCXX${CPP_STANDARD}Extensions${CPP_EXTENSION}.test PROPERTIES CXX_STANDARD_REQUIRED TRUE)
      set_target_properties(LanguageCXX${CPP_STANDARD}Extensions${CPP_EXTENSION}.test PROPERTIES CXX_EXTENSIONS ${CPP_EXTENSION})
      if("${CPP_STANDARD}" STREQUAL 98)
        target_link_libraries(LanguageCXX${CPP_STANDARD}Extensions${CPP_EXTENSION}.test PRIVATE Khaos::Headers KhaosTestFlags)
        add_test(NAME "Test the Language CXX${CPP_STANDARD} extensions ${CPP_EXTENSION}" COMMAND LanguageCXX${CPP_STANDARD}Extensions${CPP_EXTENSION}.test)
      else()
        target_link_libraries(LanguageCXX${CPP_STANDARD}Extensions${CPP_EXTENSION}.test PRIVATE Khaos::Headers doctest_with_main KhaosTestFlags)
        doctest_discover_tests(LanguageCXX${CPP_STANDARD}Extensions${CPP_EXTENSION}.test)
      endif()
    endforeach()
  endif()
endforeach()

set(CC_STANDARDS "90;99;11;17")
set(CC_EXTENSIONS "ON;OFF")
foreach(CC_STANDARD ${CC_STANDARDS})
  list(FIND CMAKE_C_COMPILE_FEATURES c_std_${CC_STANDARD} C_STANDARD_FOUND)
  if(NOT C_STANDARD_FOUND STREQUAL "-1")
    foreach(CC_EXTENSION ${CC_EXTENSIONS})
      add_executable(LanguageC${CC_STANDARD}Extensions${CC_EXTENSION}.test LanguageC.test.c)
      if("${CC_EXTENSION}" STREQUAL ON)
        target_compile_definitions(LanguageC${CC_STANDARD}Extensions${CC_EXTENSION}.test PRIVATE "-DC_STANDARD=${CC_STANDARD}" "-DC_EXTENSIONS=1")
      else()
        target_compile_definitions(LanguageC${CC_STANDARD}Extensions${CC_EXTENSION}.test PRIVATE "-DC_STANDARD=${CC_STANDARD}" "-DC_EXTENSIONS=0")
        if(MSVC AND ${CC_STANDARD} STREQUAL "99")
          target_compile_options(LanguageC${CC_STANDARD}Extensions${CC_EXTENSION}.test PRIVATE "/permissive-" "/Za")
        endif()
      endif()
      set_target_properties(LanguageC${CC_STANDARD}Extensions${CC_EXTENSION}.test PROPERTIES C_STANDARD ${CC_STANDARD})
      set_target_properties(LanguageC${CC_STANDARD}Extensions${CC_EXTENSION}.test PROPERTIES C_STANDARD_REQUIRED TRUE)
      set_target_properties(LanguageC${CC_STANDARD}Extensions${CC_EXTENSION}.test PROPERTIES C_EXTENSIONS ${CC_EXTENSION})
      target_link_libraries(LanguageC${CC_STANDARD}Extensions${CC_EXTENSION}.test PRIVATE Khaos::Headers KhaosTestFlags)
      add_test(NAME "Test the language C${CC_STANDARD} extensions ${CC_EXTENSION}" COMMAND LanguageC${CC_STANDARD}Extensions${CC_EXTENSION}.test)
    endforeach()
  endif()
endforeach()
