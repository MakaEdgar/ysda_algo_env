cmake_minimum_required(VERSION 3.20)

# Set folder name as project name (NB: no spaces!)
cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME ProjectName)   
project(${ProjectName})


# Sources
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)


# Executable
add_executable(${PROJECT_NAME} ${SRC_FILES})
