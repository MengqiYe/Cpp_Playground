cmake_minimum_required(VERSION 3.20)
project(Cpp_Playground)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(10.4_Iterators)
add_subdirectory(omp.data_sharing)
add_subdirectory(omp.exercise)
add_subdirectory(omp.initializer)

add_subdirectory(omp.parallel)
add_subdirectory(omp.reduction)
add_subdirectory(omp.task)

add_subdirectory(printable)

add_subdirectory(std.transform)
