//
// Created by 15066 on 2021/9/11.
//
#include<malloc.h>
#include<string.h>
#include "HashMap.h"
struct HashNode_{
    void *Key,*Value;
};
struct HashMap_{
    struct HashNode_ *Table;
    bool *Status;
    unsigned long long Size;
};
DCQueue HashMap_ValueToDCQueue(HashMap hashMap){
    DCQueue result = DCQueue_New();
    for(unsigned long long i=0;i<hashMap->Size;i++){
        if(hashMap->Status[i] == true){
            DCQueue_PushToLast(result,hashMap->Table[i].Value);
        }
    }
    return result;
}
DCQueue HashMap_KeyToDCQueue(HashMap hashMap){
    DCQueue result = DCQueue_New();
    for(unsigned long long i=0;i<hashMap->Size;i++){
        if(hashMap->Status[i] == true){
            DCQueue_PushToLast(result,hashMap->Table[i].Key);
        }
    }
    return result;
}
bool HashMap_ReSize(HashMap hashMap,unsigned long long size){
    void *temp = realloc(hashMap->Table,sizeof(struct HashNode_)*size);
    if(temp == NULL){
        return false;
    }
    if(temp == hashMap->Table){
        hashMap->Size = size;
        return true;
    }else{
        hashMap->Table = (struct HashNode_*)temp;
        return true;
    }
}
HashMap HashMap_New(unsigned long long size) {
    if(size == 0){
        return NULL;
    }
    HashMap hashMap = (struct HashMap_ *) malloc(sizeof(struct HashMap_));
    if (hashMap == NULL) {
        return NULL;
    }
    hashMap->Size = size;
    hashMap->Table = (struct HashNode_ *) malloc(sizeof(struct HashNode_) * size);
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