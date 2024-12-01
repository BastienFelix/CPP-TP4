# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(MyProject VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler warnings (equivalent to -Wall -Wextra)
add_compile_options(-Wall -Wextra)

# Include directories
include_directories(headers)

# Target executable
set(SOURCE_FILES
    src/main.cpp
    src/Parcelle.cpp
    src/Carte.cpp
    src/ZA.cpp
    src/ZAU.cpp
    src/ZN.cpp
    src/ZU.cpp
    src/Constructible.cpp
)

add_executable(main ${SOURCE_FILES})

# Google Test Integration
# (Assuming Google Test is added as a submodule in a folder called googletest)
add_subdirectory(googletest)  # Include Google Test
enable_testing()

# Unit test executable
add_executable(runTests
    tests/test.cpp  # Add your test file here
)

# Link Google Test libraries to the test executable
target_link_libraries(runTests gtest gtest_main)

# Add test cases
add_test(NAME MyTests COMMAND runTests)

# Custom target to run the program
add_custom_target(run
    COMMAND ./main
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Custom clean target (optional, as CMake has a built-in clean)
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} --build . --target clean
)