cmake_minimum_required(VERSION 3.16)
project(test_problem)

# Project Settings
# ----------------
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# C++ compillation flags
# ----------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wpedantic -Werror -Wall -Wextra -Wextra-semi -Wsign-compare")

# Sanitizers option
option(WITH_SANS "Enable asan and ubsan." OFF) #OFF by default
if(WITH_SANS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined")
endif()
unset(WITH_SANS CACHE)

# Build type flags
if(CMAKE_BUILD_TYPE MATCHES "DEBUG")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -fno-omit-frame-pointer")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
endif()


# Input files
set(SOURCES src/main.cpp)

# add_subdirectory(src)

add_executable(${PROJECT_NAME} ${SOURCES})
