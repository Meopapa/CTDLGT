#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "include\data_structure\data_structure.h"
#include "include\data_structure\dsa_configs.h"

// SearchBinaryTree
#define TREE_DECLARE_INIT(type) \
    int TREE_Init_##type(TreeNode_##type **root); \
    int TREE_Free_##type(TreeNode_##type *root); 
#define TREE_DECLARE_ACT(type) \
    int TREE_Insert_##type(TreeNode_##type **node, type x); \
    int TREE_DeleteNode_##type(TreeNode_##type **root, type x); \
    type TREE_Search_##type(TreeNode_##type **root, type x); 
#define TREE_DECLARE_Traversal(type, format) \
    int TREE_PreOrder_##type(TreeNode_##type *root); \
    int TREE_InOrder_##type(TreeNode_##type *root); \
    int TREE_PostOrder_##type(TreeNode_##type *root); 

// Core of DSW and AVL
#define ROTATION_DECLARE(type) \
    int TREE_LeftRotate_##type(); \
    int TREE_RightRotate_##type(); \

#endif