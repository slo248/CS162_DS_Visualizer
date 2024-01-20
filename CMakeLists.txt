cmake_minimum_required(VERSION 3.10)
project(DS-Visual)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directory
set(OSBit 32)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OSBit 64)
endif()

set(AllOutDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${AllOutDir})

# Copy data folder to output directory
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# Find SFML, if not found, download it
find_package(SFML 2.6 COMPONENTS graphics window system audio)

if(NOT SFML_FOUND)
    include(FetchContent)

    FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
    )

    FetchContent_GetProperties(SFML)

    if(NOT SFML_POPULATED)
        FetchContent_Populate(SFML)
        add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
    endif()

    set(SFML_INCLUDE_DIR ${sfml_SOURCE_DIR}/include)
endif()

set(SFML_LIBRARIES sfml-graphics sfml-window sfml-system sfml-audio)

#######################################################
# Add source files

add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(src/Core)

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} Core)

#######################################################
# Add tests
include(CTest)
enable_testing()

file(GLOB_RECURSE TEST_SOURCES tests/*.cpp)

foreach(TEST_SOURCE ${TEST_SOURCES})
    # Get the name of the test from the source file path
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)

    # Create an executable for the test
    add_executable(${TEST_NAME} ${TEST_SOURCE})

    # Link the test executable with any necessary libraries
    # Replace "MyLibrary" with the name of your library
    target_link_libraries(${TEST_NAME} Core)

    # Add the test
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME} WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endforeach()
