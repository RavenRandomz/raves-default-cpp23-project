set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE TEST_SRC ${PROJECT_SOURCE_DIR} test/*.cpp)
file(GLOB_RECURSE REGULAR_SRC ${PROJECT_SOURCE_DIR} src/*.cpp)
file(GLOB_RECURSE MODULES_SRC ${PROJECT_SOURCE_DIR} src/*.cppm)

message(TRACE ${REGULAR_SRC})

cmake_minimum_required(VERSION 4.2.0)
project(derp)

add_executable(
    module_test
    ${REGULAR_SRC}
    ${MODULES_SRC}
)

target_sources(
    module_test PRIVATE
    FILE_SET all_my_modules TYPE CXX_MODULES
    BASE_DIRS
        ${PROJECT_SOURCE_DIR}
    FILES
    ${MODULES_SRC}
)

#cmake_minimum_required(VERSION 3.30)
#project(main)
#
#set(CMAKE_CXX_STANDARD 23)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD ON)
#
## Clang because of modules support
#if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
#    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 18.1.2)
#        message(FATAL_ERROR "Clang version must be at least 18.1.2")
#    endif()
#else()
#    message(FATAL_ERROR "Only Clang is supported")
#endif()
#
#add_executable(
#    main
#    src/main.cpp
#    src/test.cppm)
#target_sources(main PUBLIC FILE_SET allModules TYPE CXX_MODULES FILES src/test.cppm)
#target_compile_options(main PRIVATE
#        -stdlib=libc++
#)
