#include<stdio.h>
#include<stdlib.h>
#include "include/Tree.h"
#include <time.h>
#include "Windows.h"

int main() {
    Tree tr = Tree_NewTree();
    int *a = malloc(4*10000000);
    for(int i=0;i<10000000;i++){
        a[i] = rand();
        Tree_Insert(&tr,a[i],999);
    }
    for(int i=0;i<10000000;i++){
        if(999 != Tree_Get(tr,a[i])){
            puts("????????????");
        }
    }
    Tree_Destroy(&tr);
    return 0;
}


