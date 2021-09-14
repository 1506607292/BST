#include "include/TreeMap.h"
#include "include/random.h"
#include "stdio.h"
int main() {
    unsigned int lang = 50;
    unsigned long long *b = randUnsignedLong(lang);
    for (int ii = 0; ii < 1; ii++) {
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
        Tree_Display(tr);
        for (unsigned long long i = 0; i < lang; i++) {
            Tree_Delete(tr, (void*)b[i]);
        }
        printf("%lld\n",(long long)clock()-start);
        puts("=====================");
        free(tr);
        //Tree_Destroy(tr);
    }
    free(b);
    return 0;
}