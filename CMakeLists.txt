cmake_minimum_required(VERSION 3.11.0)

project(cdemo )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    gtest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.8.3
)
FetchContent_MakeAvailable(gtest benchmark)
set_target_properties(benchmark PROPERTIES
    CMAKE_BUILD_TYPE Release
)

add_executable(cdemo main.cpp)
target_link_libraries(cdemo benchmark::benchmark )

