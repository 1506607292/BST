#include<stdio.h>
#include<stdlib.h>
#include "include/Tree.h"
#include <time.h>
#include "Windows.h"

int main() {
    unsigned int *array,lang;
    puts("Input The Length :\n");
    scanf_s("%d",&lang);
    Tree tr = Tree_NewTree();
    array = malloc(4*lang);
    if(!array){
        perror("NULL ARRAY !");
        return -1;
    }
    for(int ii=0;ii<1000;ii++){
        printf_s("%d\n",ii);
        for(int i=0;i<lang;i++){
            array[i] = rand();
            Tree_Insert(&tr,array[i],0);
        }
        for(int i=0;i<lang;i++){
            Tree_Delete(&tr,array[i]);
        }
    }
    system("pause");
    system("pause");
    //Tree_Destroy(&tr);
    system("pause");
    free(array);
    system("pause");
    return 0;
}


