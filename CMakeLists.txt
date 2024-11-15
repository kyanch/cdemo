cmake_minimum_required(VERSION 3.13)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(PICO_SDK_PATH "/home/kyanch/ws/pico-sdk")
set(PICO_BOARD pico2)
# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import)

pico_sdk_init()

project(cdemo VERSION 0.0.1 LANGUAGES CXX C)

# 遍历src下所有cpp文件
file(GLOB _SOURCES_ ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(main ${_SOURCES_})

target_link_libraries(main pico_stdlib)
pico_add_extra_outputs(main)

set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/output")
