//
// Created by 15066 on 2021/9/14.
//
#pragma once
#ifndef MALLOC_H
#define MALLOC_H

#include<malloc.h>

#endif
////////////////////////////////
#include "ArrayList.h"

ArrayList ArrayList_New() {
    ArrayList array = (ArrayList_ *) malloc(sizeof(ArrayList_));
    if (array == NULL) {
        return NULL;
    }
    array->Array = (void *) malloc(sizeof(void *) * 1024);
    if (array->Array == NULL) {
        free(array);
        return NULL;
    }
    array->Size = 0;
    array->Capacity = 1;
    return array;
}

void ArrayList_Destroy(ArrayList array) {
    free(array->Array);
    free(array);
}

#include "stdio.h"

bool ArrayList_SetCapacity(ArrayList array, unsigned long long capacity) {
    void *temp = realloc(array->Array, sizeof(void *) * capacity);
    if (temp == NULL) {
        return false;
    }
    if (temp != array->Array) {
        array->Array = temp;
    }
    array->Capacity = capacity;
    return true;
}

bool ArrayList_PushBack(ArrayList array, void *object) {
    if (array->Size < array->Capacity) {
        array->Array[array->Size++] = object;
        return true;
    } else {
        if (ArrayList_SetCapacity(array, array->Capacity * 2)) {
            array->Array[array->Size++] = object;
            return true;
        }
        return false;
    }
}


bool ArrayList_Insert(ArrayList array, unsigned long long index, void *object) {
    if(array->Size > array->Capacity){
        if(!ArrayList_SetCapacity(array,array->Capacity*2)){
            return false;
        }
    }
    for (unsigned long long i = array->Size; i > index; i--) {
        array->Array[i] = array->Array[i - 1];
    }
    array->Array[index] = object;
    array->Size++;
    return true;
}

bool ArrayList_Erase(ArrayList array, unsigned long long index) {
    for (unsigned long long i = index; i < array->Size; i++) {
        array->Array[i] = array->Array[i + 1];
    }
    if(array->Size < array->Capacity/2 && array->Capacity > 1024){
        ArrayList_SetCapacity(array,array->Capacity/2);
    }
    array->Size--;
    return true;
}
