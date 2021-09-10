//
// Created by 15066 on 2021/9/8.
//
#ifndef HASHTABLE_H
#define HASHTABLE_H
///////////////////////////
#ifndef STDBOOL_H
#define STDBOOL_H

#include<stdbool.h>

#endif
///////////////////////////
typedef struct TreeNode {
    struct TreeNode *P, *L, *R;
    void *Key;
    void *Value;
    int a[16384];
} TreeNode;
typedef struct Tree{
    struct TreeNode *root;
}Tree;

Tree Tree_NewTree();

bool Tree_Insert(Tree *tree, void *key, void *value);

bool Tree_SetOrInsert(Tree *tree, void *key, void *value);

void Tree_Set(TreeNode *tree, void *key, void *value);

void Tree_Delete(Tree *tree, void *key);

void Tree_Destroy(Tree *tree);

void Tree_Show(Tree *tree);
void Tree_Display(Tree *tree);
void *Tree_Get(TreeNode *tree, void *key);

#endif //HASHTABLE_H