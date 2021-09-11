//#include<stdio.h>
//#include<stdlib.h>
//#include "include/TreeMap.h"
//#include <time.h>
//#include "Windows.h"
//
//int main() {
//    clock_t start;
//    start=clock();
//    int lang = 10000000;
//    Tree tr = Tree_NewTree();
//    int *a = malloc(4*lang);
//    for(int i=0;i<lang;i++){
//        a[i] = rand();
//        Tree_Insert(&tr,a[i],999);
//    }
//    printf_s("%d\n",clock()-start);
//    start = clock();
//    for(int i=0;i<lang;i++){
//        Tree_Get(tr,a[i]);
//    }
//    printf_s("%d\n",clock()-start);
//    start = clock();
//    for(int i=0;i<lang;i++){
//        Tree_Delete(&tr,a[i]);
//    }
//    printf_s("%d",clock()-start);
//    Tree_Destroy(&tr);
//    return 0;
//}



#include<stdio.h>
#include<stdlib.h>
#include "include/TreeMap.h"
#include <time.h>
#include "Windows.h"
int main() {
    int lang = 10000000,ll = 10000;
    Tree *ts = malloc(ll*sizeof(Tree));
    for(int i=0;i<ll;i++){
        ts[i] = Tree_NewTree();
    }
    clock_t start;
    start=clock();
    int *a = malloc(4*lang);
    for(int i=0;i<lang;i++){
        a[i] = rand();
        Tree_Insert(ts+(a[i]%ll),a[i],999);
    }
    printf_s("%d\n",clock()-start);
    start = clock();
    for(int i=0;i<lang;i++){
        Tree_Get(ts[a[i]%ll],a[i]);
    }
    printf_s("%d\n",clock()-start);
    start = clock();
    for(int i=0;i<lang;i++){
        Tree_Delete(ts+(a[i]%ll),a[i]);
    }
    printf_s("%d",clock()-start);
    for(int i=0;i<ll;i++){
        Tree_Destroy(ts+i);
    }
    free(a);
    free(ts);
    return 0;
}


