#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//
// Created by 15066 on 2021/9/11.
//
#include "include/TreeMap.h"
int *xipai(int lang) {
    int* a = malloc(4 * lang);
    for (int i = 0; i < lang; i++) {
        a[i] = i;
    }
    int length = lang;
    srand(time(NULL));
    while (--length) {
        int temp = rand()%(length+1);
        int t = a[length];
        a[length] = a[temp];
        a[temp] = t;
    }
    return a;
}
int main() {
    unsigned int lang = 500000;
    int *b = xipai(lang);
    for (int ii = 0; ii < 1000000; ii++) {
        clock_t start = clock();
        TreeMap tr = Tree_NewTree();
        for (int i = 0; i < lang; i++) {
            Tree_Insert(tr, b[i], 0);
        }
        printf_s("%d\n",clock()-start);
        start = clock();
        for (int i = 0; i < lang; i++) {
            Tree_Get(tr, b[i]);
        }
        printf_s("%d\n",clock()-start);
        start = clock();
        for (int i = 0; i < lang; i++) {
            Tree_Delete(tr, b[i]);
        }
        printf_s("%d\n",clock()-start);
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
