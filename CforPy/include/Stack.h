//
// Created by 15066 on 2021/9/8.
//

#ifndef STACK_H
#define STACK_H
///////////////////////////
#ifndef STDBOOL_H
#define STDBOOL_H

#include<stdbool.h>

#endif
///////////////////////////
typedef struct StackNode {
    struct StackNode *Below;
    void *object;
} StackNode;

typedef struct Stack {
    struct StackNode *Top;
} Stack;

Stack Stack_New();

void Stack_Push(Stack *, void *);

void *Stack_Top(Stack *);

void *Stack_Pop(Stack *);

void Stack_Destroy(Stack *);

bool Stack_IsEmpty(Stack *);

#endif //STACK_H
