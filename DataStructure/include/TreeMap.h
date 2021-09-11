//
// Created by 15066 on 2021/9/11.
//

#ifndef TREEMAP_H
#define TREEMAP_H
///////////////////////////
#ifndef STDBOOL_H
#define STDBOOL_H
#include<stdbool.h>
#endif
///////////////////////////
#ifndef STACK_H
#include "Stack.h"
#define STACK_H
#endif
typedef struct TreeNode_ {
    struct TreeNode_ *P, *L, *R;
    void *Key;
    void *Value;
} TreeNode_;
typedef struct TreeMap_{
    struct TreeNode_ *root;
}TreeMap_;
typedef TreeMap_* TreeMap;
TreeMap Tree_NewTree();
bool Tree_Insert(TreeMap tree, void *key, void *value);
bool Tree_SetOrInsert(TreeMap tree, void *key, void *value);
bool Tree_Set(TreeMap tree, void *key, void *value);
void *Tree_Get(TreeMap tree, void *key);
bool Tree_Delete(TreeMap tree, void *key);
void Tree_Destroy(TreeMap tree);
void Tree_Show(TreeMap tree);
void Tree_Display(TreeMap tree);
Stack Tree_KeyToStack(TreeMap tree);
//Stack Tree_ValueToStack(Tree tree);

#endif //TREEMAP_H
