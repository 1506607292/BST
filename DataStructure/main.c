#include <unistd.h>
#include "include/TreeMap.h"
#include "include/DCQueue.h"
#include "include/ArrayList.h"
#include "include/random.h"
#include "include/Stack.h"
#include "stdio.h"

int main() {
    unsigned int length = 5000;
    ArrayList array = ArrayList_New();
    TreeMap tree = Tree_New();
    unsigned long long *a = randUnsignedLong(length);
    for (unsigned long long i = 0; i < length; i++) {
        ArrayList_PushBack(array, (void*)a[i]);
        Tree_Insert(tree, (void*)a[i], (void*)i);
    }
    DCQueue queue = Tree_KeyToDCQueue(tree);
    void *start = DCQueue_Get(queue);
    DCQueue_MoveToNext(queue);

    sleep(1);
    while (DCQueue_Get(queue) != start) {
        DCQueue_MoveToNext(queue);
        printf("%p \n",DCQueue_Get(queue));
    }
    sleep(1);
    ArrayList_Destroy(array);

    printf("====%d\n", Tree_ContainKey(tree,(void*)5555));

    Tree_Destroy(tree);
    free(a);
    return 0;
}