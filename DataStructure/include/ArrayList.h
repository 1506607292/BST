//
// Created by 15066 on 2021/9/14.
//
#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include<stdbool.h>
typedef struct ArrayList_* ArrayList;
void *ArrayList_Get(ArrayList array,unsigned long long index);
unsigned long long ArrayList_Size(ArrayList array);
ArrayList ArrayList_New();
void ArrayList_Destroy(ArrayList array);
bool ArrayList_PushBack(ArrayList array,void *object);
bool ArrayList_Insert(ArrayList array,unsigned long long index,void *object);
bool ArrayList_Erase(ArrayList array, unsigned long long index);
#endif //ARRAYLIST_H
