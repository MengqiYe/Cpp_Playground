cmake_minimum_required(VERSION 3.12)
project(Cpp_Playground)

set(CMAKE_CXX_STANDARD 11)

if(False)
    add_subdirectory(10.4_Iterators)
    add_subdirectory(memset.struct)
    add_subdirectory(omp.data_sharing)
    add_subdirectory(omp.exercise)
    add_subdirectory(omp.parallel)
    add_subdirectory(omp.reduction)
    add_subdirectory(omp.task)

    add_subdirectory(printable)

    add_subdirectory(std.iterator)

    add_subdirectory(std.transform)
    add_subdirectory(std.unordered_map)

    add_subdirectory(str)

endif()

add_subdirectory(stl.bind)
