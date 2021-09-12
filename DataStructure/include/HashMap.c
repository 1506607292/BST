//
// Created by 15066 on 2021/9/11.
//
#pragma once
#ifndef MALLOC_H
#define MALLOC_H
#include<malloc.h>
#endif
////////////////////////////////
#include "HashMap.h"
#include <vcruntime_string.h>
HashMap HashMap_New(unsigned int size) {
    if(size == 0){
        return NULL;
    }
    HashMap hashMap = (HashMap_ *) malloc(sizeof(HashMap_));
    if (hashMap == NULL) {
        return NULL;
    }
    hashMap->Size = size;
    hashMap->Table = (HashNode_ *) malloc(sizeof(HashNode_) * size);
    if (hashMap->Table == NULL) {
        free(hashMap);
        return NULL;
    }
    hashMap->Status = (bool *) malloc(sizeof(bool) * size);
    if (hashMap->Status == NULL) {
        free(hashMap->Table);
        free(hashMap);
        return NULL;
    }
    memset(hashMap->Status, 0, sizeof(bool) * size);
    return hashMap;
}

void HashMap_Destroy(HashMap hashMap) {
    free(hashMap->Status);
    free(hashMap->Table);
    free(hashMap);
}

bool HashMap_Set(HashMap hashMap, void *key, void *value) {
    unsigned int temp = (long long unsigned int) key % hashMap->Size;
    for (unsigned int i = temp; i < hashMap->Size; i++) {
        if (hashMap->Status[i] == true && hashMap->Table[i].Key == key) {
            hashMap->Table[i].Value = value;
            return true;
        }
        if (hashMap->Status[i] == false) {
            hashMap->Status[i] = true;
            hashMap->Table[i].Key = key;
            hashMap->Table[i].Value = value;
            return true;
        }
    }
    for (unsigned int i = temp - 1; i > -1; i--) {
        if (hashMap->Status[i] == false) {
            hashMap->Status[i] = true;
            hashMap->Table[i].Key = key;
            hashMap->Table[i].Value = value;
            return true;
        }
        if (hashMap->Status[i] == true && hashMap->Table[i].Key == key) {
            hashMap->Table[i].Value = value;
            return true;
        }
    }
    return false;
}

void *HashMap_Get(HashMap hashMap, void *key) {
    for (unsigned int i =(long long unsigned int) key % hashMap->Size; i < hashMap->Size; i++) {
        if (hashMap->Table[i].Key == key && hashMap->Status[i] == true) {
            return hashMap->Table[i].Value;
        }
    }
    for (unsigned int i =(long long unsigned int) key % hashMap->Size- 1; i > -1; i--) {
        if (hashMap->Table[i].Key == key && hashMap->Status[i] == true) {
            return hashMap->Table[i].Value;
        }
    }
    return NULL;
}
bool HashMap_Erase(HashMap hashMap, void *key){
    unsigned int temp = (long long unsigned int) key % hashMap->Size;
    for (unsigned int i = temp; i < hashMap->Size; i++) {
        if (hashMap->Table[i].Key == key && hashMap->Status[i] == true) {
            hashMap->Status[i] = false;
            return true;
        }
    }
    for (unsigned int i = temp - 1; i > -1; i--) {
        if (hashMap->Table[i].Key == key && hashMap->Status[i] == true) {
            hashMap->Status[i] = false;
            return true;
        }
    }
    return false;
}