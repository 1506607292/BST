//
// Created by 15066 on 2021/9/11.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<stdbool.h>
#include"DCQueue.h"
typedef struct HashMap_* HashMap;
bool HashMap_ReSize(HashMap hashMap,unsigned long long size);
HashMap HashMap_New(unsigned long long size);
void HashMap_Destroy(HashMap hashMap);
bool HashMap_Set(HashMap hashMap,void *key,void *value);
void *HashMap_Get(HashMap hashMap, void *key);
bool HashMap_Erase(HashMap hashMap, void *key);
DCQueue HashMap_KeyToDCQueue(HashMap hashMap);
DCQueue HashMap_ValueToDCQueue(HashMap hashMap);
#endif //HASHTABLE_H
