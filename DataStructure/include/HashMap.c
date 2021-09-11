//
// Created by 15066 on 2021/9/11.
//
#pragma once

#include "Stack.h"

#ifndef MALLOC_H
#define MALLOC_H

#include<malloc.h>

#endif
////////////////////////////////
#include "HashMap.h"
#include <vcruntime_string.h>
#include "stdio.h"
HashMap HashMap_NewHashMap(unsigned int size) {
    if(size == 0){
        return NULL;
    }
    HashMap hashMap = (HashMap_ *) malloc(sizeof(HashMap_));
    if (hashMap == NULL) {
        return NULL;
    }
    hashMap->size = size;
    hashMap->table = (HashNode_ *) malloc(sizeof(HashNode_) * size);
    if (hashMap->table == NULL) {
        free(hashMap);
        return NULL;
    }
    hashMap->status = (bool *) malloc(sizeof(bool) * size);
    if (hashMap->status == NULL) {
        free(hashMap->table);
        free(hashMap);
        return NULL;
    }
    memset(hashMap->status, 0, sizeof(bool) * size);
    return hashMap;
}

void HashMap_Destroy(HashMap hashMap) {
    free(hashMap->status);
    free(hashMap->table);
    free(hashMap);
}

bool HashMap_Set(HashMap hashMap, void *key, void *value) {
    unsigned int temp = (unsigned int) key % hashMap->size;
    for (unsigned int i = temp; i < hashMap->size; i++) {
        if (hashMap->status[i] == true && hashMap->table[i].Key == key) {
            hashMap->table[i].Value = value;
            return true;
        }
        if (hashMap->status[i] == false) {
            hashMap->status[i] = true;
            hashMap->table[i].Key = key;
            hashMap->table[i].Value = value;
            return true;
        }
    }
    for (unsigned int i = temp - 1; i > -1; i--) {
        if (hashMap->status[i] == false) {
            hashMap->status[i] = true;
            hashMap->table[i].Key = key;
            hashMap->table[i].Value = value;
            return true;
        }
        if (hashMap->status[i] == true && hashMap->table[i].Key == key) {
            hashMap->table[i].Value = value;
            return true;
        }
    }
    return false;
}

void *HashMap_Get(HashMap hashMap, void *key) {
    for (unsigned int i =(unsigned int) key % hashMap->size; i < hashMap->size; i++) {
        if (hashMap->table[i].Key == key && hashMap->status[i] == true) {
            return hashMap->table[i].Value;
        }
    }
    for (unsigned int i =(unsigned int) key % hashMap->size- 1; i > -1; i--) {
        if (hashMap->table[i].Key == key && hashMap->status[i] == true) {
            return hashMap->table[i].Value;
        }
    }
    return NULL;
}
bool HashMap_Erase(HashMap hashMap, void *key){
    unsigned int temp = (unsigned int) key % hashMap->size;
    for (unsigned int i = temp; i < hashMap->size; i++) {
        if (hashMap->table[i].Key == key && hashMap->status[i] == true) {
            hashMap->status[i] = false;
            return true;
        }
    }
    for (unsigned int i = temp - 1; i > -1; i--) {
        if (hashMap->table[i].Key == key && hashMap->status[i] == true) {
            hashMap->status[i] = false;
            return true;
        }
    }
    return false;
}


void HashMap_Show(HashMap hashMap){
    for(unsigned i = 0;i<hashMap->size;i++){
        if(hashMap->status[i] == true){
            printf("%d : %d\n",(int)hashMap->table[i].Key,(int)hashMap->table[i].Value);
        }
    }
}