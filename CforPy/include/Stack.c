//
// Created by 15066 on 2021/9/8.
//

#include "Stack.h"
///////////////////////////
#ifndef MALLOC_H
#define MALLOC_H

#include<malloc.h>

#endif
///////////////////////////
#ifndef STDIO_H

#include<stdio.h>

#define STDIO_H
#endif

///////////////////////////
StackNode *Stack_NewNode() {
    StackNode *pointer = malloc(sizeof(StackNode));
    if (pointer == NULL) {
        return NULL;
    }
    pointer->object = NULL;
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
    StackNode *pointer = Stack_NewNode();
    pointer->object = object;
    pointer->Below = stack->Top;
    stack->Top = pointer;
}

void *Stack_Top(Stack *stack) {
    if (stack == NULL) {
        return NULL;
    }
    if (Stack_IsEmpty(*stack)) {
        return NULL;
    }
    return stack->Top->object;
}

void *Stack_Pop(Stack *stack) {
    if (stack == NULL) {
        return NULL;
    }
    if (Stack_IsEmpty(*stack)) {
        return NULL;
    }
    void *object = stack->Top->object;
    void *oldTop = stack->Top;
    stack->Top = stack->Top->Below;
    free(oldTop);
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