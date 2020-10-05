## Set minimum cmake
cmake_minimum_required(VERSION 3.15)

# Declare project
project(Catch)

# Add library
add_library(Catch INTERFACE)

# Include directory
target_include_directories(Catch INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/../)