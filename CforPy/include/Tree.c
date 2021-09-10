//
// Created by 15066 on 2021/9/8.
//
#ifndef MALLOC_H
#include<malloc.h>
#define MALLOC_H
#endif
///////////////////////////
#ifndef STDIO_H
#include<stdio.h>
#define STDIO_H
#endif
///////////////////////////
#ifndef STACK_H
#include "Stack.h"
#define STACK_H
#endif
///////////////////////////
#include "Tree.h"
///////////////////////////
TreeNode *Tree_NewNULLNode() {
    TreeNode *pointer = (TreeNode *) malloc(sizeof(TreeNode));
    if (pointer == NULL) { return NULL; }
    pointer->P = NULL;
    pointer->L = NULL;
    pointer->R = NULL;
    pointer->Key = NULL;
    pointer->Value = NULL;
    return pointer;
}
TreeNode *Tree_NewNode(void *key, void *value) {
    TreeNode *pointer = (TreeNode *) malloc(sizeof(TreeNode));
    if (pointer == NULL) { return NULL; }
    pointer->P = NULL;
    pointer->L = NULL;
    pointer->R = NULL;
    pointer->Key = key;
    pointer->Value = value;
    return pointer;
}
Tree Tree_NewTree() {
    Tree tree = {NULL};
    return tree;
}
bool Tree_IsRoot(Tree *tree, TreeNode *p) {
    return tree->root == p;
}
bool Tree_SetOrInsert(Tree *tree, void *key, void *value) {
    if (tree->root == NULL) {
        tree->root = Tree_NewNode(key, value);
        if (tree->root == NULL) {
            return false;
        }
        tree->root->P = NULL;
        return true;
    }
    TreeNode *temp = tree->root;
    while (1) {
        if (temp->Key == key) {
            temp->Key = key;
            temp->Value = value;
            return true;
        }
        if (temp->Key < key && temp->R != NULL) {
            temp = temp->R;
        } else if (temp->Key > key && temp->L != NULL) {
            temp = temp->L;
        } else {
            break;
        }
    }
    TreeNode *pointer = Tree_NewNode(key, value);
    if (pointer == NULL) {
        return false;
    }
    temp->Key < key ? (temp->R = pointer) : (temp->L = pointer);
    pointer->P = temp;
    return true;
}
bool Tree_Insert(Tree *tree, void *key, void *value) {
    if (tree->root == NULL) {
        tree->root = Tree_NewNode(key, value);
        if (tree->root == NULL) {
            return false;
        }
        tree->root->P = NULL;
        return true;
    }
    TreeNode *temp = tree->root;
    while (1) {
        if (temp->Key == key) {
            return false;
        }
        if (temp->Key < key && temp->R != NULL) {
            temp = temp->R;
        } else if (temp->Key > key && temp->L != NULL) {
            temp = temp->L;
        } else {
            break;
        }
    }
    TreeNode *pointer = Tree_NewNode(key, value);
    if (pointer == NULL) {
        return false;
    }
    temp->Key < key ? (temp->R = pointer) : (temp->L = pointer);
    pointer->P = temp;
    return true;
}
void *Tree_Get(Tree tree, void *key) {
    TreeNode *pointer = tree.root;
    while (pointer != NULL) {
        if (pointer->Key == key) {
            return pointer->Value;
        }
        if (pointer->Key > key) {
            pointer = pointer->L;
        } else {
            pointer = pointer->R;
        }
    }
    return NULL;
}
void Tree_Destroy(Tree *tree) {
    TreeNode *pointer = tree->root;
    Stack stack = Stack_New();
    Stack stackFree = Stack_New();
    while (!Stack_IsEmpty(stack) || pointer) {
        while (pointer != NULL) {
            Stack_Push(&stack, pointer);
            pointer = pointer->L;
        }
        if (!Stack_IsEmpty(stack)) {
            pointer = Stack_Pop(&stack);
            Stack_Push(&stackFree, pointer);
            pointer = pointer->R;
        }
    }
    Stack_Destroy(&stack);
    while (!Stack_IsEmpty(stackFree)) {
        free(Stack_Pop(&stackFree));
    }
    tree->root = NULL;
}
void Tree_Delete(Tree *tree, void *key) {
    TreeNode *pointer = tree->root;
    while (pointer != NULL) {
        if (pointer->Key == key) {
            break;
        }
        if (pointer->Key > key) {
            pointer = pointer->L;
        } else {
            pointer = pointer->R;
        }
    }
    if (pointer == NULL) {
        return;
    }
    if (pointer->L == NULL && pointer->R == NULL) {// 修改顶点问题
        if (Tree_IsRoot(tree, pointer)) {
            tree->root = NULL;
            free(pointer);
            return;
        }
        if (pointer->P->L == pointer) {
            pointer->P->L = NULL;
        } else {
            pointer->P->R = NULL;
        }
        free(pointer);
    } else if (pointer->R == NULL) {
        if (Tree_IsRoot(tree, pointer)) {
            tree->root = pointer->L;
            pointer->L->P = NULL;
            free(pointer);
            return;
        }
        if (pointer->P->L == pointer) { //pointer 是左子树
            pointer->P->L = pointer->L;
        } else {
            pointer->P->R = pointer->L;
        }
        pointer->L->P = pointer->P;
        free(pointer);
    } else if (pointer->L == NULL) {
        if (Tree_IsRoot(tree, pointer)) {
            tree->root = pointer->R;
            pointer->R->P = NULL;
            free(pointer);
            return;
        }
        if (pointer->P->L == pointer) {
            pointer->P->L = pointer->R;
        } else {
            pointer->P->R = pointer->R;
        }
        pointer->R->P = pointer->P;
        free(pointer);
    } else {
        TreeNode *ii;
        for (ii = pointer->R; ii->L != NULL; ii = ii->L);//右子树最小的一个
        pointer->Key = ii->Key;
        pointer->Value = ii->Value;
        if (ii->P->L == ii) {
            ii->P->L = ii->R;
        } else {
            ii->P->R = ii->R;
        }
        if(ii->R != NULL){
            ii->R->P = ii->P;
        }
        free(ii);
    }
}
void Tree_Display_(TreeNode *tree,int layer) {
    if(!tree){
        return;
    }
    Tree_Display_(tree->L,layer+1);
    for(int i=0;i<layer*3;i++){
        putchar(' ');
    }
    printf_s("%d:%d\n",tree->Key,tree->Value);
    Tree_Display_(tree->R,layer+1);
}
void Tree_Display(Tree tree) {
    if (tree.root == NULL) {
        return;
    } else {
        Tree_Display_(tree.root,0);
    }
}
void Tree_Show_(TreeNode *tree) {
    if (tree == NULL) {
        return;
    }
    Stack stack = Stack_New();
    while (!Stack_IsEmpty(stack) || tree) {
        while (tree != NULL) {
            Stack_Push(&stack, tree);
            tree = tree->L;
        }
        if (!Stack_IsEmpty(stack)) {
            tree = Stack_Pop(&stack);
            printf_s("%p : %p\n", tree->Key, tree->Value);
            tree = tree->R;
        }
    }
    Stack_Destroy(&stack);
}
void Tree_Show(Tree tree) {
    Tree_Show_(tree.root);
}
bool Tree_Set(Tree tree, void *key, void *value) {
    if (tree.root == NULL) {
        return false;
    }
    TreeNode *pointer = tree.root;
    while (pointer != NULL) {
        if (pointer->Key == key) {
            pointer->Value = value;
            return true;
        }
        if (pointer->Key > key) {
            pointer = pointer->L;
        } else {
            pointer = pointer->R;
        }
    }
    return false;
}