cmake_minimum_required(VERSION 4.2.0)
set(CMAKE_CXX_STANDARD 23)
project(derp)
set(CMAKE_GENERATOR Ninja)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(module_test)

target_sources(
    module_test PRIVATE
    FILE_SET all_my_modules TYPE CXX_MODULES
    BASE_DIRS
        ${PROJECT_SOURCE_DIR}
    FILES
        src/test.cppm
)

target_sources(module_test PRIVATE
    src/main.cpp
)
