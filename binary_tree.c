#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

BinaryTree *root;

void SORT_PreOrder(BinaryTree *node)
{
    if(root == NULL || node == NULL) return;
    printf("%d", node->value);
    SORT_PreOrder(node->left_child);
    SORT_PreOrder(node->right_child);
}

void SORT_PostOrder(BinaryTree *node)
{
    if(root == NULL || node == NULL) return;
    SORT_PostOrder(node->left_child);
    SORT_PostOrder(node->right_child);
    printf("%d", node->value);
}
 
int SORT_InOrder(BinaryTree *node)
{
    if(root == NULL || node == NULL) return 0;
    SORT_InOrder(node->left_child);
    printf("%d", node->value);
    SORT_InOrder(node->right_child);
}
// =================================
BinaryTree* NODE_NodeSearchByValue(BinaryTree *node, int value)
{
    BinaryTree *found;
    if (node == NULL) return NULL;               
    if (node->value == value) return node;        
    found = NODE_NodeSearchByValue(node->left_child, value);
    if (found != NULL) return found;        
    return NODE_NodeSearchByValue(node->right_child, value);

}

inline BinaryTree* NODE_SiblingSearch(BinaryTree *node)
{
    if(node == root) return NULL;
    return node->parent->right_child;
}

int NODE_LCA()
{}

void NODE_WaySearch(BinaryTree *node)
{
    if(node == NULL) return;
    BinaryTree *node_way;
    node_way = node;
    while(node_way != NULL)
    {
        printf("%d", node_way->value);
        node_way = node_way->parent;
    }
}

int NODE_LargestFind(BinaryTree *node)
{   
    if(node == NULL) return node->value;

    int right, left;

    left = NODE_LargestFind(node->left_child);
    right = NODE_LargestFind(node->right_child);

    return (left > node->value ? (left > right ? left : right) : node->value);
}
// =================================
int TREE_Init()
{
    root = NULL;
}

int TREE_TreeGrow(BinaryTree *node_parent, int value)
{
    BinaryTree *node_new;

    node_new = malloc(sizeof(BinaryTree));
    node_new->value = value;
    node_new->left_child = NULL;
    node_new->right_child = NULL;
    if(root == NULL)
    {
        root = node_new;
        node_new->parent = NULL;
    }
    else node_new->parent = node_parent;
}

int TREE_TreeCut(BinaryTree *node)
{
    if(node == NULL) return 0;
    TREE_TreeCut(node->left_child);
    TREE_TreeCut(node->right_child);
    free(node);
}

int TREE_BalanceCheck(BinaryTree *node)
{
    
}

int TREE_TreeSize();
int TREE_LeafNumber();
int TREE_TreeHeight();
int TREE_TreeSum(BinaryTree *node)
{   
    if(root == NULL || node == NULL) return 0;
    TREE_TreeSum(node->left_child);
    TREE_TreeSum(node->right_child);
    return node->value + TREE_TreeSum(node->left_child) + TREE_TreeSum(node->right_child);
}

int main(int agrc, char* agrv[]){}