#include "include/TreeMap.h"
#include "include/random.h"
#include "stdio.h"
int main() {
    unsigned int lang = 500000;
    unsigned long long *b = randUnsignedLong(lang);
    for (int ii = 0; ii < 1000000; ii++) {
        clock_t start = clock();
        TreeMap tr = Tree_New();
        for (int i = 0; i < lang; i++) {
            Tree_Insert(tr, (void*)b[i], 0);
        }
        printf("%lld\n",(long long)clock()-start);
        start = clock();
        for (int i = 0; i < lang; i++) {
            Tree_Get(tr, (void*)b[i]);
        }
        printf("%lld\n",(long long)clock()-start);
        start = clock();
        for (unsigned long long i = 0; i < lang; i++) {
            Tree_Delete(tr, (void*)b[i]);
        }
        printf("%lld\n",(long long)clock()-start);
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