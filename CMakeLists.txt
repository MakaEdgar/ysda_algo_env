cmake_minimum_required(VERSION 3.16)
project(test_problem)

# Project Settings
# ----------------
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# C++ compillation flags
# ----------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wpedantic -Werror -Wall -Wextra -Wextra-semi -Wsign-compare")

# Build type flags
if(CMAKE_BUILD_TYPE MATCHES "DEBUG")
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -fno-omit-frame-pointer")
else()
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
endif()

# Sanitizers option
option(WITH_SANS "Enable asan and ubsan." OFF) #OFF by default
if(WITH_SANS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined")
endif()
unset(WITH_SANS CACHE)


function(add_clang_tidy_target TARGET_NAME TARGET_FILES)
    add_custom_target(
        clang-tidy-${TARGET_NAME}
        COMMAND clang-tidy
        -header-filter=.*
        -warnings-as-errors=*
        -p .
        ${TARGET_FILES}
        --
    )
endfunction()

# Sources
# -------
add_subdirectory(src)
