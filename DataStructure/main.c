//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "include/HashMap.h"
//#include "include/DCQueue.h"
//#include "include/random.h"
//#define MaxSize 1024
//
//double calculate(char* str){
//    char *left = (char*) malloc(sizeof(char)* strnlen(str,MaxSize));
//    char *middle = (char*) malloc(sizeof(char)* strnlen(str,MaxSize));
//    char *right = (char*) malloc(sizeof(char)* strnlen(str,MaxSize));
//    memset(left,0,sizeof(char)*strnlen(str,MaxSize));
//    memset(middle,0,sizeof(char)*strnlen(str,MaxSize));
//    memset(right,0,sizeof(char)*strnlen(str,MaxSize));
//    unsigned int Left=0,Right=0;
//    while(str[Left] >='0' && str[Left] <='9'){
//        left[Left] = str[Left];
//        Left++;
//    }
//    puts(left);
//    for(unsigned int i=strnlen(str,MaxSize)-1;str[i] >='0' && str[i] <='9';i--){
//        Right = i;
//    }
//    for(unsigned int i=0;str[Right+i] >='0' && str[Right+i] <='9';i++){
//        right[i] = str[Right+i];
//    }
//    puts(right);
//    free(left);
//    free(middle);
//    free(right);
//    return 0;
//}
//int main() {
//    char *str = "123*456-888";
//    calculate(str);
//    return 0;
//}

#include "include/TreeMap.h"
#include "include/random.h"
#include "stdio.h"
int main() {
    unsigned int lang = 500000;
    int *b = randUnsignedLong(lang);
    for (int ii = 0; ii < 1000000; ii++) {
        clock_t start = clock();
        TreeMap tr = Tree_New();
        for (int i = 0; i < lang; i++) {
            Tree_Insert(tr, b[i], 0);
        }
        printf("%d\n",clock()-start);
        start = clock();
        for (int i = 0; i < lang; i++) {
            Tree_Get(tr, b[i]);
        }
        printf("%d\n",clock()-start);
        start = clock();
        for (int i = 0; i < lang; i++) {
            Tree_Delete(tr, b[i]);
        }
        printf("%d\n",clock()-start);
        start = clock();
        puts("=====================");
        free(tr);
        //Tree_Destroy(tr);
    }
    free(b);
    system("pause");
    system("pause");
    system("pause");
    system("pause");
    return 0;
}