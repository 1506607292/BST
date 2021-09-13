//
// Created by 15066 on 2021/9/12.
//
#pragma once
#ifndef DATASTRUCTURE_DCQUEUE_H
#define DATASTRUCTURE_DCQUEUE_H

#ifndef STDBOOL_H
#define STDBOOL_H
#include<stdbool.h>
#endif
///////////////////////////
typedef struct DCQueueNode_{
    struct DCQueueNode_ *Last,*Next;
    void *Object;
    int a[1024];
}DCQueueNode_;
typedef struct DCQueue_{
    DCQueueNode_ *Position;
    int a[1024];
}DCQueue_;
typedef DCQueue_* DCQueue;
DCQueue DCQueue_New();
bool DCQueue_PushToLast(DCQueue queue,void *object);
bool DCQueue_PushToNext(DCQueue queue,void *object);
void *DCQueue_PopToLast(DCQueue queue);
void *DCQueue_PopToNext(DCQueue queue);
void DCQueue_Destroy(DCQueue queue);
void DCQueue_Show(DCQueue queue);
#endif //DATASTRUCTURE_DCQUEUE_H
