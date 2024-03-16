cmake_minimum_required(VERSION 3.20)

project(cdemo VERSION 0.0.1 LANGUAGES CXX C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS -Wall -Werror)

add_executable(main src/main.cpp)
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/output")

add_subdirectory(ds)

file(GLOB LEETCODE "leetcode/*.cpp" "leetcode/*.c" "leetcode/*/*.cpp" "leetcode/*/*.c")
foreach(SOURCE ${LEETCODE})
    get_filename_component(CODE_NAME ${SOURCE} NAME_WE)
    add_executable(${CODE_NAME} ${SOURCE})
endforeach()
