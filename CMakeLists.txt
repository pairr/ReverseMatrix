cmake_minimum_required(VERSION 3.26)
project(testing_test)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(run ${SOURCE_FILES})

include_directories(MatrixLib)
add_subdirectory(MatrixLib)

target_link_libraries(run MatrixLib)

add_subdirectory(Tests)