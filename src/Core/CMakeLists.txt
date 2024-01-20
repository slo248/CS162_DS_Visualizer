file(GLOB CORE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_executable(Core ${CORE_SOURCES})
target_include_directories(Core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
