#include "include/TreeMap.h"
#include "include/DCQueue.h"
#include "include/random.h"
#include "stdio.h"
int main() {
    unsigned int lang = 50000;
    for (int ii = 0; ii < 1; ii++) {
        unsigned long long *b = randUnsignedLong(lang);
        clock_t start = clock();
        TreeMap tr = Tree_New();
        DCQueue q = DCQueue_New();
        for (int i = 0; i < lang; i++) {
            Tree_Insert(tr, (void*)b[i], 0);
        }
        printf("tree insert time %lld\n",(long long)clock()-start);
        start = clock();
        for (int i = 0; i < lang; i++) {
            DCQueue_PushToLast(q,b[i]);
        }
        printf("queue insert time %lld\n",(long long)clock()-start);
        free(b);
        b = randUnsignedLong(lang);
        start = clock();
        for (int i = 0; i < lang; i++) {
            Tree_Get(tr, (void*)b[i]);
        }
        printf("tree get time %lld\n",(long long)clock()-start);
        start = clock();
        for(int i=0;i<lang;i++){
            while(q->Position->Object != b[i]){
                DCQueue_MoveToLast(q);
            }
        }
        printf("queue get time%lld\n",(long long)clock()-start);
        start = clock();
        for (unsigned long long i = 0; i < lang; i++) {
            DCQueue_PopToLast(q);
        }
        printf("queue pop time%lld\n",(long long)clock()-start);
        start = clock();
        for (unsigned long long i = 0; i < lang; i++) {
            Tree_Delete(tr, (void*)b[i]);
        }
        printf("tree delete time%lld\n",(long long)clock()-start);
        puts("=====================");
        free(tr);
        free(q);
        free(b);
    }
    return 0;
}