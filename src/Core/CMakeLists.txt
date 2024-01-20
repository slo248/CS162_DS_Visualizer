# CMakeLists.txt for Core
file(GLOB CORE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(Core ${CORE_SOURCES})
target_include_directories(Core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
