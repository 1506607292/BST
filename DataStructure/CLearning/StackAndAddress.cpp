#include "include/TreeMap.h"
#include "include/DCQueue.h"
#include "include/ArrayList.h"
#include "include/random.h"
#include "stdio.h"


void or(int num,int p,...){
    printf("%p %p \n????",&num,&p);
    printf("%X======\n",*((&num)));
    printf("%X======\n",*((&num)-1));
    char* temp = (char*)(&num);
    //    temp+=4;
    temp -= 1;
    printf("%c\n",*temp);
    printf("%c\n",*(temp-1));
    printf("%c\n",*(temp-2));
    printf("%c\n",*(temp-3));
}


/*
 * linux C的栈区 在我这个遍历器里面是由低到高的
 * 而大部分人的编译器是由高到低的
 * 在上边的不定参数测试中,只有向低地址寻址才能找到入栈的函数参数
 *
 * main函数里面解释了数组和指针以及数组指针的区别
 *
 * 数组可以直接+1  数组是连续 空间  但是数组指针实际上不可以 +1   这样会直接在二维数组中 出现错误 指向下一个一维数组
 *
 * 由于我是64位编译器  注意地址是64位  (本程序没有体现)
 *
 * */
int main(){
    long long int ar[10];

    long  long int *pp[10];
    pp[0] = ar;
    printf("%p %p === \n",&pp,&pp[0]);
    for(long long int i=0;i<10;i++){
        //            pp[0][i] = 666;
        ((long long int*)*pp)[i] = 666;
    }
    *(((long long *)(*(pp+1)))+5) = 1433223;
    for(int i=0;i<10;i++){
        printf("%lld\n",ar[i]);
    }
    //    or(args,0x32323232);

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