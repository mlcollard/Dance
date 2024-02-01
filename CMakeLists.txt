# Build for Dance program

cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

project(Dance)

# dance
add_executable(dance)
target_sources(dance PRIVATE dance.cpp)
target_compile_features(dance PRIVATE cxx_std_17)

# run
add_custom_target(run
    COMMENT "Dance"
    COMMAND $<TARGET_FILE:dance>
    DEPENDS dance
    USES_TERMINAL
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
