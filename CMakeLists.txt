cmake_minimum_required(VERSION 3.20)
project(LeetCodeCpp)

set(CMAKE_CXX_STANDARD 14)

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>")

add_executable(Array_lc54 Array_lc54.cpp)
add_executable(DualPointer_lc141 DualPointer_lc141.cpp)
add_executable(BreadthFirstSearch_lc102 BreadthFirstSearch_lc102.cpp)
add_executable(Stack_lc20 Stack_lc20.cpp)
add_executable(Offer03 Offer03.cpp)