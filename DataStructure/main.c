#include <stdio.h>
#include <stdlib.h>
//
// Created by 15066 on 2021/9/11.
//

#include "include/Stack.h"

int main() {
    for(int ii=0;ii<8000;ii++){
         printf_s("%d\n",ii);
         Stack st = Stack_New();
         for(int i=0;i<100000;i++){
             Stack_Push(st,i);
         }
         Stack_Destroy(st);
     }
     system("pause");
     system("pause");
     system("pause");
     system("pause");
    return 0;
}

//
//#include <stdio.h>
//#include <stdlib.h>
////
//// Created by 15066 on 2021/9/11.
////
//#include "include/TreeMap.h"
//
//int main() {
//    TreeMap tr = Tree_NewTree();
//    Tree_Insert(tr,4000,10);
//    Tree_Insert(tr,125,1044234);
//    Tree_Insert(tr,14,10423);
//    Tree_Insert(tr,142,10423);
//    Tree_Insert(tr,4234,10424);
//    Tree_Insert(tr,4321,142430);
//    Tree_Insert(tr,49871,143240);
//    Stack s = Tree_KeyToStack(tr);
//    while(!Stack_IsEmpty(s)){
//        printf_s("key = %d\n", Stack_Pop(s));
//    }
//    Stack_Destroy(s);
//    Tree_Display(tr);
//    Tree_Destroy(tr);
//    system("pause");
//    return 0;
//}