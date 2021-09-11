//////////////////////////////////
#ifndef STDBOOL_H
#define STDBOOL_H
#include<stdbool.h>
#endif
//////////////////////////////////

#ifndef STACK_H
#define STACK_H

typedef struct StackNode_ {
    struct StackNode_ *Below;
    void *object;
} StackNode_;

typedef struct Stack_ {
    struct StackNode_ *Top;
} Stack_;
typedef Stack_* Stack;
Stack Stack_New();
void Stack_Push(Stack stack, void *object);
void *Stack_Top(Stack stack);
void *Stack_Pop(Stack stack);
void Stack_Destroy(Stack stack);
bool Stack_IsEmpty(Stack stack);

#endif //STACK_H