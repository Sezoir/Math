## Set minimum cmake (note mbed-cmake requires at least CMake 3.12)
cmake_minimum_required(VERSION 3.15)

#########################################################
# Options
#########################################################
set(ENABLE_UNIT_TESTS ON)



#########################################################
# Setup project
#########################################################

## ROOT project
project(ROOT)

# Add project
add_subdirectory(Math)

# Add unit tests
add_subdirectory(UnitTests)

