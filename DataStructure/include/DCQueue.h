//
// Created by 15066 on 2021/9/12.
//
#ifndef DCQUEUE_H
#define DCQUEUE_H
#include<stdbool.h>
typedef struct DCQueue_* DCQueue;
DCQueue DCQueue_New();
void *DCQueue_Get(DCQueue queue);
bool DCQueue_PushToLast(DCQueue queue,void *object);
bool DCQueue_PushToNext(DCQueue queue,void *object);
void *DCQueue_PopToLast(DCQueue queue);
void *DCQueue_PopToNext(DCQueue queue);
void DCQueue_Destroy(DCQueue queue);
void DCQueue_MoveToLast(DCQueue queue);
void DCQueue_MoveToNext(DCQueue queue);
#endif //DCQUEUE_H
