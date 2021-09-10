cmake_minimum_required(VERSION 3.20)
project(CforPy C)




include_directories("C:/Program Files/Python39/include")

find_library("Python" "python39_d" "C:/Program Files/Python39/libs")
# 添加目标链接
#set(PYTHON_LINK C:/Program Files/Python39/libs)
#link_libraries( ${PYTHON_LINK})

set(CMAKE_C_STANDARD 11)

add_executable(CforPy main.c include/Stack.c include/Stack.h include/Tree.c include/Tree.h include/Dict.c include/Dict.h)
