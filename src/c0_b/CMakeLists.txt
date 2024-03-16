cmake_minimum_required(VERSION 3.20)

# Set folder name as project name (no spaces!)
cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME ProjectName)   
project(${ProjectName})


# Sources and Headers
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB HDR_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
set(PROJECT_FILES "${SRC_FILES} ${HDR_FILES}")

# Executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Add clang tidy checks
add_clang_tidy_target(${PROJECT_NAME} ${SRC_FILES} ${HDR_FILES})
