## Set minimum cmake
cmake_minimum_required(VERSION 3.15)

# Declare project
project(Math C CXX)

# Get all source and header files (May change from a header lib in future)
#file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS *.hpp)

## Add library
add_library(${PROJECT_NAME} INTERFACE)

# Include directories
target_include_directories(${PROJECT_NAME} INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
    )

# Set c++ standard
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

