#include "data_structure/tree.h"

#define TREE_IMPLEMENT_INIT(type) \
    int TREE_Init_##type(TreeNode_##type **root) \
    { \
        if (root == NULL) return ERROR_NULL_PTR; \
        *root = NULL; \
        return SUCCESS_TRUE; \
    } \
    int TREE_Free_##type(TreeNode_##type *root) \
    { \
        if (root == NULL) return SUCCESS_TRUE; \
        TREE_Free_##type(root->left); \
        TREE_Free_##type(root->right); \
        free(root); \
        return SUCCESS_TRUE; \
    }


#define TREE_IMPLEMENT_ACT(type) \
    int TREE_Insert_##type(TreeNode_##type **root, type x) \
    { \
        TreeNode_##type *new_node; \
        if (root == NULL) return ERROR_NULL_PTR; \
        if (*root == NULL) \
        { \
            new_node = malloc(sizeof(*new_node)); \
            if (new_node == NULL) return ERROR_MEMORY_ALLOC; \
            new_node->data = x; \
            new_node->left = NULL; \
            new_node->right = NULL; \
            *root = new_node; \
            return SUCCESS_TRUE; \
        } \
        if (x < (*root)->data) return TREE_Insert_##type(&(*root)->left, x); \
        if (x > (*root)->data) return TREE_Insert_##type(&(*root)->right, x); \
        return ERROR_INDEX; \
    } \
    int TREE_DeleteNode_##type(TreeNode_##type **root, type x) \
    { \
        TreeNode_##type *replacement; \
        TreeNode_##type *successor; \
        if (root == NULL) return ERROR_NULL_PTR; \
        if (*root == NULL) return ERROR_EMPTY; \
        if (x < (*root)->data) return TREE_DeleteNode_##type(&(*root)->left, x); \
        if (x > (*root)->data) return TREE_DeleteNode_##type(&(*root)->right, x); \
        if ((*root)->left == NULL) \
        { \
            replacement = (*root)->right; \
            free(*root); \
            *root = replacement; \
            return SUCCESS_TRUE; \
        } \
        if ((*root)->right == NULL) \
        { \
            replacement = (*root)->left; \
            free(*root); \
            *root = replacement; \
            return SUCCESS_TRUE; \
        } \
        successor = (*root)->right; \
        while (successor->left != NULL) successor = successor->left; \
        (*root)->data = successor->data; \
        return TREE_DeleteNode_##type(&(*root)->right, successor->data); \
    } \
    TreeNode_##type *TREE_Search_##type(TreeNode_##type **root, type x) \
    { \
        if (root == NULL || *root == NULL) return NULL; \
        if (x < (*root)->data) return TREE_Search_##type(&(*root)->left, x); \
        if (x > (*root)->data) return TREE_Search_##type(&(*root)->right, x); \
        return *root; \
    }

#define TREE_IMPLEMENT_Traversal(type, format) \
    int TREE_PreOrder_##type(TreeNode_##type *root) \
    { \
        if (root == NULL) return ERROR_EMPTY; \
        printf(format, root->data); \
        TREE_PreOrder_##type(root->left); \
        TREE_PreOrder_##type(root->right); \
        return SUCCESS_TRUE; \
    } \
    int TREE_InOrder_##type(TreeNode_##type *root) \
    { \
        if (root == NULL) return ERROR_EMPTY; \
        TREE_InOrder_##type(root->left); \
        printf(format, root->data); \
        TREE_InOrder_##type(root->right); \
        return SUCCESS_TRUE; \
    } \
    int TREE_PostOrder_##type(TreeNode_##type *root) \
    { \
        if (root == NULL) return ERROR_EMPTY; \
        TREE_PostOrder_##type(root->left); \
        TREE_PostOrder_##type(root->right); \
        printf(format, root->data); \
        return SUCCESS_TRUE; \
    }

#define ROTATION_IMPLEMENT(type) \
    int TREE_LeftRotate_##type(TreeNode_##type **root) \
    { \
        TreeNode_##type *pivot; \
        if (root == NULL || *root == NULL) return ERROR_NULL_PTR; \
        if ((*root)->right == NULL) return ERROR_EMPTY; \
        pivot = (*root)->right; \
        (*root)->right = pivot->left; \
        pivot->left = *root; \
        *root = pivot; \
        return SUCCESS_TRUE; \
    } \
    int TREE_RightRotate_##type(TreeNode_##type **root) \
    { \
        TreeNode_##type *pivot; \
        if (root == NULL || *root == NULL) return ERROR_NULL_PTR; \
        if ((*root)->left == NULL) return ERROR_EMPTY; \
        pivot = (*root)->left; \
        (*root)->left = pivot->right; \
        pivot->right = *root; \
        *root = pivot; \
        return SUCCESS_TRUE; \
    }

#define TREE_IMPLEMENTATION_END 1

TREE_STRUCT(int)
TREE_DECLARE_INIT(int)
TREE_DECLARE_ACT(int)
TREE_DECLARE_Traversal(int, "%d ")
ROTATION_DECLARE(int)
TREE_IMPLEMENT_INIT(int)
TREE_IMPLEMENT_ACT(int)
TREE_IMPLEMENT_Traversal(int, "%d ")
ROTATION_IMPLEMENT(int)