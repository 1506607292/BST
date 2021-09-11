//
// Created by 15066 on 2021/9/11.
//
#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H

#ifndef STDBOOL_H
#define STDBOOL_H
#include<stdbool.h>
#endif
///////////////////////////
typedef struct HashNode_{
    void *Key,*Value;
}HashNode_;
typedef struct HashMap_{
    HashNode_ *table;
    bool *status;
    unsigned int size;
}HashMap_;
typedef HashMap_* HashMap;
HashMap HashMap_NewHashMap(unsigned int size);
void HashMap_Destroy(HashMap hashMap);
bool HashMap_Set(HashMap hashMap,void *key,void *value);
void *HashMap_Get(HashMap hashMap, void *key);
bool HashMap_Erase(HashMap hashMap, void *key);
void HashMap_Show(HashMap hashMap);
#endif //HASHTABLE_H
