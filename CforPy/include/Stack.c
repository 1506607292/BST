//
// Created by 15066 on 2021/9/8.
//

#include "Stack.h"
///////////////////////////
#ifndef MALLOC_H
#define MALLOC_H
#include<malloc.h>
#endif

StackNode *Stack_NewNULLNode() {
    StackNode *pointer = malloc(sizeof(StackNode));
    if (pointer == NULL) {
        return NULL;
    }
    pointer->object = NULL;
    pointer->Below = NULL;
    return pointer;
}
///////////////////////////
StackNode *Stack_NewNode(void *object) {
    StackNode *pointer = malloc(sizeof(StackNode));
    if (pointer == NULL) {
        return NULL;
    }
    pointer->object = object;
    pointer->Below = NULL;
    return pointer;
}

Stack Stack_New() {
    Stack stack = {NULL};
    return stack;
}

void Stack_Push(Stack *stack, void *object) {
    if (stack == NULL) {
        return;
    }
    StackNode *pointer = Stack_NewNode(object);
    if(pointer == NULL){
        return;
    }
    pointer->Below = stack->Top;
    stack->Top = pointer;
}

void *Stack_Top(Stack stack) {
    return Stack_IsEmpty(stack)?NULL:stack.Top->object;
}

void *Stack_Pop(Stack *stack) {
    if (stack == NULL) {
        return NULL;
    }
    if (Stack_IsEmpty(*stack)) {
        return NULL;
    }
    void *object = stack->Top->object;
    free(stack->Top);
    stack->Top = stack->Top->Below;
    return object;
}

bool Stack_IsEmpty(Stack stack) {
    return stack.Top == NULL;
}

void Stack_Destroy(Stack *stack) {
    if (stack == NULL) {
        return;
    }
    while (!Stack_IsEmpty(*stack)) {
        Stack_Pop(stack);
    }
    stack->Top = NULL;
}