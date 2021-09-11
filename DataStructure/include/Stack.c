#include "Stack.h"
#ifndef MALLOC_H
#define MALLOC_H
#include<malloc.h>
#endif
////////////////////////////////

StackNode_ *Stack_NewNode(void *object) {
    StackNode_ *pointer = (StackNode_*)malloc(sizeof(StackNode_));
    if (pointer == NULL) {
        return NULL;
    }
    pointer->object = object;
    pointer->Below = NULL;
    return pointer;
}

Stack Stack_New() {
    Stack stack = (Stack_*)malloc(sizeof(Stack_));
    if(stack == NULL){
        return NULL;
    }
    stack->Top = NULL;
    return stack;
}
void Stack_Push(Stack stack, void *object) {
    StackNode_ *pointer = Stack_NewNode(object);
    if (pointer == NULL) {
        return;
    }
    pointer->Below = stack->Top;
    stack->Top = pointer;
}
void *Stack_Top(Stack stack) {
    return Stack_IsEmpty(stack) ? NULL : stack->Top->object;
}
void *Stack_Pop(Stack stack) {
    if (Stack_IsEmpty(stack)) {
        return NULL;
    }
    void *object = stack->Top->object;
    void *oldTop = stack->Top;
    stack->Top = stack->Top->Below;
    free(oldTop);
    return object;
}
bool Stack_IsEmpty(Stack stack) {
    return stack->Top == NULL;
}
void Stack_Destroy(Stack stack) {
    while (!Stack_IsEmpty(stack)) {
        Stack_Pop(stack);
    }
    free(stack);
}