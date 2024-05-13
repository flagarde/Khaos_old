add_executable(KhaosVersion.example KhaosVersion.cpp)
target_link_libraries(KhaosVersion.example PRIVATE Khaos::Khaos)

add_executable(Compiler.example Compiler.cpp)
target_link_libraries(Compiler.example PRIVATE Khaos::Khaos)
