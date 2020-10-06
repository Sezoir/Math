## Set minimum cmake
cmake_minimum_required(VERSION 3.15)

#########################################################
# Options
#########################################################
OPTION(ENABLE_UNIT_TESTS "Enables all unit tests." OFF)


#########################################################
# Unit tests
#########################################################
# Add each folder for testing
function (add_folder FOLDER)
    # Get all source files
    file(GLOB_RECURSE GLOB_RESULT CONFIGURE_DEPENDS ${FOLDER}/*.c ${FOLDER}/*.cpp)
    # Append source files
    set(SOURCE_FILES ${SOURCE_FILES} ${GLOB_RESULT} PARENT_SCOPE)
endfunction()

if (ENABLE_UNIT_TESTS)
    # Declare project
    project(MathUnitTests C CXX)

    # Add Catch library
    add_subdirectory(Catch)

    # Add Tests
    add_folder(Containers)

    # Add executable
    add_executable(${PROJECT_NAME}
            main.cpp
            ${SOURCE_FILES}
            )

    # Set c++ standard
    target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

    # Link libraries
    target_link_libraries(${PROJECT_NAME} PUBLIC
            Math    Catch
            )
endif (ENABLE_UNIT_TESTS)
