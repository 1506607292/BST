////
//// Created by 15066 on 2021/9/9.
////
//#ifndef MALLOC_H
//#include<malloc.h>
//#define MALLOC_H
//#endif
/////////////////////////////
//#ifndef STDIO_H
//#include<stdio.h>
//#define STDIO_H
//#endif
//
/////////////////////////////
//#include "Dict.h"
//
//Dict Dict_NewDict(unsigned int size){
//    Dict dict = {size,(TreeNode**)malloc(sizeof(TreeNode*)*size)};
//    for(int i=0;i<size;i++){
//        dict.Array[i] = NULL;
//    }
//    return dict;
//}
//
//void Dict_Destroy(Dict dict){
//    for(int i=0;i<dict.Size;i++){
//        if(dict.Array[i] != NULL){
//            Tree_Destroy(dict.Array[i]);
//        }
//    }
//    free(dict.Array);
//}
//void *Dict_Get(Dict dict,void *key){
//    return Tree_Get(dict.Array[(unsigned int)key % dict.Size],key);
//}
//
//void Dict_Set(Dict dict,void *key,void *value){
//    if(dict.Array[(unsigned int)key % dict.Size] == NULL){
//        //perror("Nonexistent key !");
//    }
//    Tree_Set(dict.Array[(unsigned int)key % dict.Size],key,value);
//}
//void Dict_InsertOrSet(Dict dict,void *key,void *value){
//    if(dict.Array[(unsigned int)key % dict.Size] == NULL){
//        dict.Array[(unsigned int)key % dict.Size] = Tree_NewTree();
//        dict.Array[(unsigned int)key % dict.Size]->Key = key;
//        dict.Array[(unsigned int)key % dict.Size]->Value = value;
//        return;
//    }
//    Tree_Set(dict.Array[(unsigned int)key % dict.Size],key,value);
//}
//void Dict_Insert(Dict dict,void *key,void *value){
//    if(dict.Array[(unsigned int)key % dict.Size] == NULL){
//        dict.Array[(unsigned int)key % dict.Size] = Tree_NewTree();
//        dict.Array[(unsigned int)key % dict.Size]->Key = key;
//        dict.Array[(unsigned int)key % dict.Size]->Value = value;
//        return;
//    }
//    Tree_Insert(dict.Array[(unsigned int)key % dict.Size],key,value);
//}
//
//void Dict_Delete(Dict dict,void *key){
//    if(dict.Array[(unsigned int)key % dict.Size]->Key == key){
//        Tree_Destroy(dict.Array[(unsigned int)key % dict.Size]);
//        dict.Array[(unsigned int)key % dict.Size] = NULL;
//    }
//    else{
//        Tree_Delete(dict.Array[(unsigned int)key % dict.Size],key);
//    }
//}