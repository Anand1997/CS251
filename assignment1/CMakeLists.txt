cmake_minimum_required(VERSION 3.15)
project(Assignment1-Solution)
find_package(Threads)
find_package(Git QUIET)

# Set compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic -pedantic-errors -Wno-error=deprecated-copy -g")

# Define all testing related content here
enable_testing()

# Bring in GoogleTest
include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG 96683ee  # release-1.14.0
)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()
include_directories(${googletest_SOURCE_DIR}/googletest/include)


# Include project headers
include_directories(./include)
# Define the source files and dependencies for the executable
set(SOURCE_FILES
    src/SimpleArray.cpp
    src/AllocationTracker.cpp
    tests/main.cpp
    tests/simpleArrayTest.cpp
    tests/moreTests.cpp
)
enable_testing()
# Make the project root directory the working directory when we run
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(testing ${SOURCE_FILES})
add_dependencies(testing gtest)
target_link_libraries(testing gtest ${CMAKE_THREAD_LIBS_INIT})

include(Dart)
# Use Clang as the compiler
set(CMAKE_CXX_COMPILER "clang++")