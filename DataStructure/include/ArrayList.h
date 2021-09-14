//
// Created by 15066 on 2021/9/14.
//
#pragma once
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#ifndef STDBOOL_H
#define STDBOOL_H
#include<stdbool.h>
#endif
///////////////////////////
typedef struct ArrayList_{
    void **Array;
    long long unsigned Size;
    long long unsigned Capacity;
}ArrayList_;
typedef ArrayList_* ArrayList;
ArrayList ArrayList_New();
void ArrayList_Destroy(ArrayList array);
bool ArrayList_PushBack(ArrayList array,void *object);
bool ArrayList_Insert(ArrayList array,unsigned long long index,void *object);
bool ArrayList_Erase(ArrayList array, unsigned long long index);
#endif //ARRAYLIST_H
