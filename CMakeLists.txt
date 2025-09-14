cmake_minimum_required(VERSION 3.16)
project(PixelArtify VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#
# Define include directories
# - 'include' for our own project's public headers
# - 'third_party' for vendored dependencies like stb and cxxopts
#
include_directories(
    include
    third_party
)

#
# Add the main executable target
#
add_executable(pixel_artify src/main.cpp src/image_processor.cpp)

#
# Enable testing with CTest
#
enable_testing()

#
# Find GoogleTest package
#
find_package(GTest REQUIRED)

#
# Add the test executable
#
add_executable(pixel_artify_tests tests/test_image_processor.cpp src/image_processor.cpp)

#
# Link the test executable with GoogleTest libraries
#
target_link_libraries(pixel_artify_tests GTest::GTest GTest::Main)

#
# Add the test to CTest for automated execution
#
include(GoogleTest)
gtest_add_tests(TARGET pixel_artify_tests)

#
# Installation instructions (optional)
#
install(TARGETS pixel_artify DESTINATION bin)
