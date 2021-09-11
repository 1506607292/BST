//
// Created by 15066 on 2021/9/12.
//
// compare the speed with c++ unordered_map and map
#include <iostream>
#include <map>
#include <unordered_map>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *random(unsigned int length) { // remember to free the array
    int *a = (int*)malloc(4 * length);
    if(a == NULL){
        return NULL;
    }
    for (int i = 0; i < length; i++) {
        a[i] = i;
    }
    srand((unsigned int) time(NULL));
    while (--length) {
        int temp = rand() % (length + 1);
        int t = a[length];
        a[length] = a[temp];
        a[temp] = t;
    }
    return a;
}
class A{
public:
    int a;
protected:
    int b;
private:
    int c;
};
class B:private A{
public:
    B(){
    }
};
int main() {
    unsigned int lang = 500000;
    int* a = random(lang);
    if (a == NULL) {
        return NULL;
    }
    clock_t start = clock();
    for (int ii = 0; ii < 1000; ii++) {
        //        std::hash<int,int> ha;
        //        std::map<int,int> ha;
        std::unordered_map<int,int> ha;
        ha.reserve(lang);
        for (int i = 0; i < lang; i++) {
            ha[a[i]]= i;
        }
        printf_s("%d\n", clock() - start);
        start = clock();
        for (int i = 0; i < lang; i++) {
            ha[a[i]];
        }
        printf_s("%d\n", clock() - start);
        start = clock();
        for (int i = 0; i < lang; i++) {
            ha.erase(a[i]);
        }
        printf_s("%d\n", clock() - start);
        start = clock();
        puts("==============");
    }
    free(a);
    system("pause");
    return 0;
}
