cmake_minimum_required(VERSION 3.20)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)

add_executable(DataStructure main.c include/Stack.h include/Stack.c include/TreeMap.h include/TreeMap.c include/HashMap.c include/HashMap.h)
