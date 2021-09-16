//
// Created by 15066 on 2021/9/16.
//

#include "String.h"
#include <malloc.h>
struct String_{
    unsigned long long Length;
    char *Object;
};

String String_New(){
    String  string = (struct String_*)malloc(sizeof(struct String_));
    if(string == NULL){
        return NULL;
    }
    string->Length = 1024;
    string->Object = (char*) malloc(sizeof(char)*1024);
    if(string->Object == NULL){
        free(string);
        return NULL;
    }
    return string;
}
void String_Destroy(String string){
    free(string->Object);
    free(string);
}
