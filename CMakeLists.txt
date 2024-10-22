cmake_minimum_required(VERSION 3.29)
project(template_matrix)

set(CMAKE_CXX_STANDARD 20)

add_executable(matrix_t main.cpp)

add_library(MatrixLib INTERFACE)

target_include_directories(MatrixLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(matrix_t MatrixLib)

add_executable(tests_run test.cpp)

target_link_libraries(tests_run MatrixLib)