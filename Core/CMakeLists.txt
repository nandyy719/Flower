add_library(fvm fvm.cpp)
add_library(fasm fasm.cpp)

target_include_directories(fvm PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Core")
target_include_directories(fasm PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Core")