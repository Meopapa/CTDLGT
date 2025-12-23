#ifndef TREE_H
#define TREE_H

typedef struct BinaryTree
{
    int value;
    BinaryTree *parent, *left_child, *right_child;
}BinaryTree;

int SORT_PreOrder();
int SORT_PostOrder();
int SORT_InOrder();
int NODE_NodeSearch();
int NODE_FatherSearch();
int NODE_SiblingSearch();
int NODE_LCA();
int NODE_WaySearch();
int TREE_Init();
int TREE_TreeGrow();
int TREE_TreeCut();
int TREE_BalanceCheck();
int TREE_TreeSize();
int TREE_LeafNumber();
int TREE_TreeHeight();


#endif