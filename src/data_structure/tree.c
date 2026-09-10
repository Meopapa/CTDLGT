#include "include\data_structure\tree.h"
#include "include\data_structure\data_structure.h"
#include "include\data_structure\dsa_configs.h"

// search binary tree
#define TREE_IMPLEMENT_INIT(type) \
    int TREE_Init_##type(TreeNode_##type **root) \
    { \
        root == NULL; \
    } \
    int TREE_Free_##type(TreeNode_##type *root) \
    { \
        if(root == NULL) return ERROR_NULL_PTR; \
        if(root->left != NULL) TREE_Free_##type(root->left); \
        if(root->right != NULL) TREE_Free_##type(root->right); \
        free(root); \
        root = NULL; \
    }
#define TREE_IMPLEMENT_ACT(type) \
    int TREE_Insert_##type(TreeNode_##type **node, type x) \
    { \
        TreeNode_##type *new_node; \
        if(node == NULL) \
        { \
            new_node->data = x; \
            new_node->left = new_node->right = NULL; \
            node = new_node; \
        } \
        else \
        { \
            if(x < node->data) TREE_Insert_##type(node->left, x); \
            if(x > node->data) TREE_Insert_##type(node->right, x); \
            else return ERROR_INDEX; \
        } \
    } \
    int TREE_DeleteNode_##type(TreeNode_##type **node, type x) \
    { \
        if(node == NULL) return ERROR_NULL_PTR; \
        if(x < node->data) TREE_DeleteNode_##type(node->left, x); \
        if(x > node->data) TREE_DeleteNode_##type(node->right, x); \
        else \
        { \
            TreeNode_##type *d1, *d2; \
            if(node->left == NULL) \
            { \
                d1 = node; \
                node = node->right; \
            } \
            if(node->rigth == NULL) \
            { \
                d1 = node; \
                node = node->left; \
            } \
            else \
            { \
                d1 = node->left; \
                if(d1->right == NULL) \
                { \
                    node->data = d1->data; \
                    node->left = d1->left; \
                } \
                else \
                { \
                    do \
                    { \
                        d2 = d1; \
                        d1 = d1->rigth; \
                    } while(d1->right != NULL); \
                    node->data = d1->data; \
                    d2->right = d1->left; \
                } \
            } \
        } \
    } \
    *TreeNode_##type TREE_Search_##type(TreeNode_##type **root, type x) \
    { \
        if(root == NULL) return NULL; \
        if(x < root->data) return TREE_Search_##type(root->left, x); \
        if(x > root->data) return TREE_Search_##type(root->right, x); \
        else return root; \
    }
#define TREE_IMPLEMENT_Traversal(type, format) \
    int TREE_PreOrder_##type(TreeNode_##type *root) \
    { \
        if(root == NULL) return ERROR_EMPTY; \
        printf(format, root->data); \
        TREE_PreOrder_##type(root->left); \
        TREE_PreOrder_##type(root->right); \
    } \
    int TREE_InOrder_##type(TreeNode_##type *root) \
    { \
        if(root == NULL) return ERROR_EMPTY; \
        TREE_PreOrder_##type(root->left); \
        printf(format, root->data); \
        TREE_PreOrder_##type(root->right); \
    } \
    int TREE_PostOrder_##type(TreeNode_##type *root) \
    { \
        if(root == NULL) return ERROR_EMPTY; \
        TREE_PreOrder_##type(root->left); \
        TREE_PreOrder_##type(root->right); \
        printf(format, root->data); \
    } \

// Core of DSW and AVL
#define ROTATION_IMPLEMENT(type) \
    int TREE_LeftRotate_##type(TreeNode_##type **root) \
    { \
        if(root == NULL || *root == NULL) return ERROR_NULL_PTR; \
        if(root->right == NULL) return ERROR_EMPTY; \
        TreeNode_##type *p, *r; \
        p = *root; \
        r = p->right; \
        p->right = r->left; \
        r->left = p; \
        *root = r; \
    } \
    int TREE_RightRotate_##type(TreeNode_##type **root) \
    { \
        if(root == NULL || *root == NULL) return ERROR_NULL_PTR; \
        if(root->right == NULL) return ERROR_EMPTY; \
        TreeNode_##type *p, *r; \
        p = *root; \
        r = p->left; \
        p->left = r->right; \
        r->right = p; \
        *root = r; \
    } \
