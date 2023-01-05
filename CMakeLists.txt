cmake_minimum_required (VERSION 3.8)

project (Flower VERSION 0.1 DESCRIPTION "Compiler and runtime for the FLower language")

enable_testing()
add_subdirectory(Core)
find_package(GTest CONFIG REQUIRED)

add_executable(flower main.cpp)
add_executable(flower_tests tests.cpp)
target_link_libraries(flower_tests PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
add_test(NAME flower_tests COMMAND flower_tests)

target_link_libraries(flower PRIVATE fvm)
target_link_libraries(flower PRIVATE fasm)

