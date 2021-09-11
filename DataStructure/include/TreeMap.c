//
// Created by 15066 on 2021/9/11.
//
#pragma once
#include "TreeMap.h"
///////////////////////////
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
TreeNode_ *Tree_NewNode(void *key, void *value) {
    TreeNode_ *pointer = (TreeNode_ *) malloc(sizeof(TreeNode_));
    if(pointer == NULL){
        return NULL;
    }
    pointer->P = NULL;
    pointer->L = NULL;
    pointer->R = NULL;
    pointer->Key = key;
    pointer->Value = value;
    return pointer;
}
bool Tree_IsRoot(TreeMap tree, TreeNode_ *p) {
    return tree->root == p;
}
TreeMap Tree_NewTreeMap() {
    TreeMap tree = (TreeMap_*)malloc(sizeof(TreeMap_));
    if(tree == NULL){
        return NULL;
    }
    tree->root = NULL;
    return tree;
}
bool Tree_Insert(TreeMap tree, void *key, void *value){
    if (tree->root == NULL) {
        tree->root = Tree_NewNode(key, value);
        if (tree->root == NULL) {
            return false;
        }
        tree->root->P = NULL;
        return true;
    }
    TreeNode_ *temp = tree->root;
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
    TreeNode_ *pointer = Tree_NewNode(key, value);
    if (pointer == NULL) {
        return false;
    }
    temp->Key < key ? (temp->R = pointer) : (temp->L = pointer);
    pointer->P = temp;
    return true;
}
bool Tree_SetOrInsert(TreeMap tree, void *key, void *value){
    if (tree->root == NULL) {
        tree->root = Tree_NewNode(key, value);
        if (tree->root == NULL) {
            return false;
        }
        tree->root->P = NULL;
        return true;
    }
    TreeNode_ *temp = tree->root;
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
    TreeNode_ *pointer = Tree_NewNode(key, value);
    if (pointer == NULL) {
        return false;
    }
    temp->Key < key ? (temp->R = pointer) : (temp->L = pointer);
    pointer->P = temp;
    return true;
}
bool Tree_Set(TreeMap tree, void *key, void *value){
    if (tree->root == NULL) {
        return false;
    }
    TreeNode_ *pointer = tree->root;
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
void *Tree_Get(TreeMap tree, void *key) {
    TreeNode_ *pointer = tree->root;
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
bool Tree_Delete(TreeMap tree, void *key){
    TreeNode_ *pointer = tree->root;
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
        return false;
    }
    if (pointer->L == NULL && pointer->R == NULL) {// 修改顶点问题
        if (Tree_IsRoot(tree, pointer)) {
            tree->root = NULL;
            free(pointer);
            return true;
        }
        if (pointer->P->L == pointer) {
            pointer->P->L = NULL;
        } else {
            pointer->P->R = NULL;
        }
    } else if (pointer->R == NULL) {
        if (Tree_IsRoot(tree, pointer)) {
            tree->root = pointer->L;
            pointer->L->P = NULL;
            free(pointer);
            return true;
        }
        if (pointer->P->L == pointer) { //pointer 是左子树
            pointer->P->L = pointer->L;
        } else {
            pointer->P->R = pointer->L;
        }
        pointer->L->P = pointer->P;
    } else if (pointer->L == NULL) {
        if (Tree_IsRoot(tree, pointer)) {
            tree->root = pointer->R;
            pointer->R->P = NULL;
            free(pointer);
            return true;
        }
        if (pointer->P->L == pointer) {
            pointer->P->L = pointer->R;
        } else {
            pointer->P->R = pointer->R;
        }
        pointer->R->P = pointer->P;
    } else {
        TreeNode_ *ii;
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
        pointer = ii;
    }
    free(pointer);
    return true;
}
void Tree_Destroy(TreeMap tree){
    TreeNode_ *pointer = tree->root;
    Stack stack = Stack_New();
    Stack stackToDestroy = Stack_New();
    while (!Stack_IsEmpty(stack) || pointer) {
        while (pointer != NULL) {
            Stack_Push(stack, pointer);
            pointer = pointer->L;
        }
        if (!Stack_IsEmpty(stack)) {
            pointer = Stack_Pop(stack);
            Stack_Push(stackToDestroy, pointer);
            pointer = pointer->R;
        }
    }
    Stack_Destroy(stack);
    while (!Stack_IsEmpty(stackToDestroy)) {
        free(Stack_Pop(stackToDestroy));
    }
    Stack_Destroy(stackToDestroy);
    free(tree);
}
void Tree_Show(TreeMap tree){
    TreeNode_ *pointer = tree->root;
    if (pointer == NULL) {
        return;
    }
    Stack stack = Stack_New();
    while (!Stack_IsEmpty(stack) || pointer) {
        while (pointer != NULL) {
            Stack_Push(stack, pointer);
            pointer = pointer->L;
        }
        if (!Stack_IsEmpty(stack)) {
            pointer = Stack_Pop(stack);
            printf_s("%p : %p\n", pointer->Key, pointer->Value);
            pointer = pointer->R;
        }
    }
    Stack_Destroy(stack);
}
void Tree_Display_(TreeNode_ *tree,int layer) {
    if(!tree){
        return;
    }
    Tree_Display_(tree->L,layer+1);
    for(int i=0;i<layer*3;i++){
        putchar(' ');
    }
    printf_s("%d:%d\n",(int)tree->Key,(int)tree->Value);
    Tree_Display_(tree->R,layer+1);
}
void Tree_Display(TreeMap tree){
    if (tree->root == NULL) {
        return;
    } else {
        Tree_Display_(tree->root,0);
    }
}
Stack Tree_KeyToStack(TreeMap tree){
    TreeNode_ *pointer = tree->root;
    Stack stack = Stack_New();
    Stack result = Stack_New();
    while (!Stack_IsEmpty(stack) || pointer) {
        while (pointer != NULL) {
            Stack_Push(stack, pointer);
            pointer = pointer->L;
        }
        if (!Stack_IsEmpty(stack)) {
            pointer = Stack_Pop(stack);
            Stack_Push(result, pointer->Key);
            pointer = pointer->R;
        }
    }
    Stack_Destroy(stack);
    return result;
}

Stack Tree_ValueToStack(TreeMap tree){
    TreeNode_ *pointer = tree->root;
    Stack stack = Stack_New();
    Stack result = Stack_New();
    while (!Stack_IsEmpty(stack) || pointer) {
        while (pointer != NULL) {
            Stack_Push(stack, pointer);
            pointer = pointer->L;
        }
        if (!Stack_IsEmpty(stack)) {
            pointer = Stack_Pop(stack);
            Stack_Push(result, pointer->Value);
            pointer = pointer->R;
        }
    }
    Stack_Destroy(stack);
    return result;
}