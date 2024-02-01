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

# install
install(PROGRAMS $<TARGET_FILE:dance> TYPE BIN)

# run fast
add_custom_target(run_fast
    COMMENT "Fast Dance"
    COMMAND $<TARGET_FILE:dance> 100
    DEPENDS dance
    USES_TERMINAL
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# run slow
add_custom_target(run_slow
    COMMENT "Slow Dance"
    COMMAND $<TARGET_FILE:dance> 800
    DEPENDS dance
    USES_TERMINAL
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
