include(Doctest)

add_executable(KhaosVersion.test KhaosVersion.test.cpp)
target_link_libraries(KhaosVersion.test PRIVATE Khaos::Headers doctest_with_main)
target_compile_definitions(KhaosVersion.test PRIVATE "-DMAJOR=${Khaos_VERSION_MAJOR}" "-DMINOR=${Khaos_VERSION_MINOR}" "-DPATCH=${Khaos_VERSION_PATCH}" "-DTWEAK=${Khaos_VERSION_TWEAK}")
doctest_discover_tests(KhaosVersion.test)

add_executable(VersionMacros.test VersionMacros.test.cpp)
target_link_libraries(VersionMacros.test PRIVATE Khaos::Headers doctest_with_main)
target_compile_definitions(VersionMacros.test PRIVATE "-DMAJOR=${Khaos_VERSION_MAJOR}" "-DMINOR=${Khaos_VERSION_MINOR}" "-DPATCH=${Khaos_VERSION_PATCH}" "-DTWEAK=${Khaos_VERSION_TWEAK}")
doctest_discover_tests(VersionMacros.test)

add_executable(CompareVersionMacros.test CompareVersionMacros.test.cpp)
target_link_libraries(CompareVersionMacros.test PRIVATE Khaos::Headers doctest_with_main)
target_compile_definitions(CompareVersionMacros.test PRIVATE "-DMAJOR=${Khaos_VERSION_MAJOR}" "-DMINOR=${Khaos_VERSION_MINOR}" "-DPATCH=${Khaos_VERSION_PATCH}" "-DTWEAK=${Khaos_VERSION_TWEAK}")
doctest_discover_tests(CompareVersionMacros.test)
