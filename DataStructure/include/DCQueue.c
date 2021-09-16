//
// Created by 15066 on 2021/9/12.
//
#include<malloc.h>
#include "DCQueue.h"
struct DCQueueNode_{
    struct DCQueueNode_ *Last,*Next;
    void *Object;
};
struct DCQueue_{
    struct DCQueueNode_ *Position;
};

void *DCQueue_Get(DCQueue queue){
    if(queue->Position == NULL){
        return NULL;
    }
    return queue->Position->Object;
}
DCQueue DCQueue_New() {
    DCQueue queue = (struct DCQueue_ *) malloc(sizeof(struct DCQueue_));
    if (queue == NULL) {
        return NULL;
    }
    queue->Position = NULL;
    return queue;
}

struct DCQueueNode_ *DCQueue_NewNode(void *object) {
    struct DCQueueNode_ *node = (struct DCQueueNode_ *) malloc(sizeof(struct DCQueueNode_));
    if (node == NULL) {
        return NULL;
    }
    node->Object = object;
    return node;
}

bool DCQueue_PushToLast(DCQueue queue, void *object) {
    if (queue->Position == NULL) {
        queue->Position = DCQueue_NewNode(object);
        if (queue->Position == NULL) {
            return false;
        }
        queue->Position->Last = queue->Position;
        queue->Position->Next = queue->Position;
        return true;
    }
    struct DCQueueNode_ *node = DCQueue_NewNode(object);
    if (node == NULL) {
        return false;
    }
    node->Last = queue->Position->Last;
    node->Next = queue->Position;
    queue->Position->Last->Next = node;
    queue->Position->Last = node;
    return true;
}

bool DCQueue_PushToNext(DCQueue queue, void *object) {
    if (queue->Position == NULL) {
        queue->Position = DCQueue_NewNode(object);
        if (queue->Position == NULL) {
            return false;
        }
        queue->Position->Last = queue->Position;
        queue->Position->Next = queue->Position;
        return true;
    }
    struct DCQueueNode_ *node = DCQueue_NewNode(object);
    if (node == NULL) {
        return false;
    }
    node->Next = queue->Position->Next;
    node->Last = queue->Position;
    queue->Position->Next->Last = node;
    queue->Position->Next = node;
    return true;
}
void *DCQueue_PopToLast(DCQueue queue){
    if (queue->Position == NULL) {
        return NULL;
    }
    void *object;
    if(queue->Position->Next == queue->Position){
        object = queue->Position->Object;
        free(queue->Position);
        queue->Position = NULL;
        return object;
    }
    struct DCQueueNode_ *temp = queue->Position;

    object = queue->Position->Object;
    queue->Position->Next->Last = queue->Position->Last;
    queue->Position->Last->Next = queue->Position->Next;
    queue->Position = queue->Position->Last;
    free(temp);
    return object;
}
void *DCQueue_PopToNext(DCQueue queue){
    if (queue->Position == NULL) {
        return NULL;
    }
    void *object;
    if(queue->Position->Next == queue->Position){
        object = queue->Position->Object;
        free(queue->Position);
        queue->Position = NULL;
        return object;
    }
    struct DCQueueNode_ *temp = queue->Position;
    object = queue->Position->Object;
    queue->Position->Next->Last = queue->Position->Last;
    queue->Position->Last->Next = queue->Position->Next;
    queue->Position = queue->Position->Next;
    free(temp);
    return object;
}
void DCQueue_Destroy(DCQueue queue) {
    if (queue->Position == NULL) {
        return;
    }
    struct DCQueueNode_ *temp = queue->Position, *last;
    do {
        last = temp;
        temp = temp->Next;
        free(last);
    } while (temp != queue->Position);
    free(queue);
}
void DCQueue_MoveToLast(DCQueue queue){
    queue->Position = queue->Position->Last;
}

void DCQueue_MoveToNext(DCQueue queue){
    queue->Position = queue->Position->Next;
}