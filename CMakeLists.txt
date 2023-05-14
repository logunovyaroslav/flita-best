cmake_minimum_required(VERSION 3.25)
project(flitaGroup C)

set(CMAKE_C_STANDARD 11)

add_executable(flitaGroup main.c main.h file_operations.h file_operations.c shell_sort.c shell_sort.h insertion_sort.c insertion_sort.h)
