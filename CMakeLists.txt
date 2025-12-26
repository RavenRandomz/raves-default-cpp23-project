# C++ 23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Allows use with other code completion tools such as clangd, clls, etc.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 

# Controversial but is practical, just use touch on CMakeLists.txt which is more convenient than having to manually edit it
# This also makes refactoring a lot easier
file(GLOB_RECURSE REGULAR_SRC ${PROJECT_SOURCE_DIR} src/*.cpp)
file(GLOB_RECURSE MODULES_SRC ${PROJECT_SOURCE_DIR} src/*.cppm)

cmake_minimum_required(VERSION 4.2.0)

# Let CMake know that this is a C++ project + project name
project(leet CXX)

add_executable(
    leet
    ${REGULAR_SRC}
    ${MODULES_SRC}
)

# Deal with windows bullshit 
# Credit to Challanger_ and GreenJD3: https://www.reddit.com/r/cpp_questions/comments/1bsh7nd/undefined_reference_to_std_open_terminal/
if (MINGW AND CMAKE_CXX_COMPILER_ID STREQUAL GNU)
  target_link_libraries(${PROJECT_NAME} stdc++exp) # std:: print, println, ...
endif()

# Support for header files (.hpp and .h), assumes all header files are in /src
# You can change this to /include if you are using that form of header project structure
target_include_directories(leet PRIVATE ${PROJECT_SOURCE_DIR}/src)
# You need to mark files as modules even if tey are listed in the sources of the executable
target_sources(
    leet PRIVATE
    FILE_SET all_my_modules TYPE CXX_MODULES
    BASE_DIRS
        ${PROJECT_SOURCE_DIR}
    FILES
    ${MODULES_SRC}
)
