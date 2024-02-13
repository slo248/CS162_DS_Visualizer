# CMakeLists.txt for Core
file(GLOB_RECURSE CORE_SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" 
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)
add_library(Core STATIC ${CORE_SOURCES})
target_include_directories(Core PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}"
)
