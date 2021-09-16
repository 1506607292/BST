cmake_minimum_required(VERSION 3.16)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)

add_executable(DataStructure main.c include/Stack.h include/Stack.c include/TreeMap.h include/TreeMap.c include/HashMap.c include/HashMap.h include/DCQueue.c include/DCQueue.h include/random.h include/ArrayList.c include/ArrayList.h CLearning/StackAndAddress.cpp include/String.c include/String.h)
