#ifndef TREE_BALANCE_H
#define TREE_BALANCE_H

typedef struct AVLNode {
    int data;
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;

int AVL_Insert(AVLNode **root, int value);
int AVL_Delete(AVLNode **root, int value);
AVLNode *AVL_Search(AVLNode *root, int value);
int AVL_Free(AVLNode *root);
int AVL_Height(const AVLNode *root);

#endif
