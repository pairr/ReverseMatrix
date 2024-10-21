cmake_minimum_required(VERSION 3.29)
project(template_matrix)

set(CMAKE_CXX_STANDARD 20)

add_executable(matrix_t main.cpp
        MatrixLib.hpp
        MatrixLib.h
)
