//
// Created by 15066 on 2021/9/12.
//

#ifndef RANDOM_H
#define RANDOM_H
#include <stdlib.h>
#include <time.h>
long long unsigned* randUnsignedLong(long long unsigned int length) { // remember to free the array
    long long unsigned* a = (long long unsigned*)malloc(sizeof(long long unsigned) * length);
    if (a == NULL) {
        return NULL;
    }
    for (long long unsigned i = 0; i < length; i++) {
        a[i] = i;
    }
    srand((unsigned int)time(NULL));
    long long unsigned temp;
    while (--length) {
        temp = rand() % (length + 1);
        long long unsigned t = a[length];
        a[length] = a[temp];
        a[temp] = t;
    }
    return a;
}
#endif //RANDOM_H
