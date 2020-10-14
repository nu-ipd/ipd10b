# Configuration for building example C programs.
cmake_minimum_required(VERSION 3.10)
project(ipd10b C)
include(.ipd/cmake/CMakeLists.txt)

add_c_program(string80
    src/string80.c)

add_c_program(stack_string
    src/stack_string.c
    src/ptr_string.c)

add_c_test_program(test_heap_string
    test/test_heap_string.c
    src/heap_string.c
    src/ptr_string.c)

add_c_test_program(test_string_fun
    test/test_string_fun.c
    src/string_fun.c
    src/heap_string.c
    src/ptr_string.c)

add_c_program(strip_concat
    src/strip_concat_main.c
    src/string_fun.c
    src/heap_string.c
    src/ptr_string.c
    src/read_line.c)
