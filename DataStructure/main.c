#include "include/TreeMap.h"
#include "include/DCQueue.h"
#include "include/ArrayList.h"
#include "include/random.h"
#include "stdio.h"
int main(){
    for(int ii=0;ii<1;ii++){
        ArrayList array = ArrayList_New();
        for(int i=0;i<3000;i++){
            ArrayList_PushBack(array,i);
        }
//        ArrayList_Insert(array,6,6666);
        ArrayList_Erase(array,6);
        for(int i=0;i<array->Size;i++){
            //printf("%d\n",array->Array[i]);
            ArrayList_Erase(array,6);
        }
        ArrayList_Destroy(array);
    }
    return 0;
//    unsigned int lang = 50000000;
//    unsigned long long *a = randUnsignedLong(lang);
//    for(int ii=0;ii<lang;ii++){
//        ArrayList array = ArrayList_New();
//        if(array == NULL){
//            return 0;
//        }
//        ArrayList_Destroy(array);
//    }
//    free(a);
}
//int main() {
//    unsigned int lang = 5000;
//    for (int ii = 0; ii < 100; ii++) {
//        unsigned long long *b = randUnsignedLong(lang);
//        TreeMap tr = Tree_New();
//        DCQueue q = DCQueue_New();
//        clock_t start = clock();
//        for (int i = 0; i < lang; i++) {
//            Tree_Insert(tr, (void*)b[i], 0);
//        }
//        printf("tree insert time %lld\n",(long long)clock()-start);
//        free(b);
//
//
//        b = randUnsignedLong(lang);
//        start = clock();
//        for (int i = 0; i < lang; i++) {
//            Tree_Get(tr, (void*)b[i]);
//        }
//        printf("tree get time %lld\n",(long long)clock()-start);
//        free(b);
//
//
//        b = randUnsignedLong(lang);
//        start = clock();
//        for (unsigned long long i = 0; i < lang; i++) {
//            Tree_Delete(tr, (void*)b[i]);
//        }
//        printf("tree delete time%lld\n",(long long)clock()-start);
//        free(b);
//
//
//        b = randUnsignedLong(lang);
//        start = clock();
//        for (int i = 0; i < lang; i++) {
//            DCQueue_PushToLast(q,(void*)b[i]);
//        }
//        printf("queue insert time %lld\n",(long long)clock()-start);
//        free(b);
//
//
//        b = randUnsignedLong(lang);
//        start = clock();
//        for(int i=0;i<lang;i++){
//            while(q->Position->Object != (void*)b[i]){
//                DCQueue_MoveToLast(q);
//            }
//        }
//        printf("queue get time%lld\n",(long long)clock()-start);
//        free(b);
//
//
//        b = randUnsignedLong(lang);
//        start = clock();
//        for (unsigned long long i = 0; i < lang; i++) {
//            DCQueue_PopToLast(q);
//        }
//        printf("queue pop time%lld\n",(long long)clock()-start);
//        puts("=====================");
//        free(tr);
//        free(q);
//        free(b);
//    }
//    return 0;
//}