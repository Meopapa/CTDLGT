#include <stdlib.h>

#include "algorithm/tree_balance.h"
#include "data_structure/dsa_configs.h"

static int max_int(int left, int right)
{
	return left > right ? left : right;
}

int AVL_Height(const AVLNode *root)
{
	return root == NULL ? 0 : root->height;
}

static void update_height(AVLNode *root)
{
	root->height = 1 + max_int(AVL_Height(root->left), AVL_Height(root->right));
}

static AVLNode *rotate_left(AVLNode *root)
{
	AVLNode *pivot = root->right;
	root->right = pivot->left;
	pivot->left = root;
	update_height(root);
	update_height(pivot);
	return pivot;
}

static AVLNode *rotate_right(AVLNode *root)
{
	AVLNode *pivot = root->left;
	root->left = pivot->right;
	pivot->right = root;
	update_height(root);
	update_height(pivot);
	return pivot;
}

static AVLNode *rebalance(AVLNode *root)
{
	int balance;

	update_height(root);
	balance = AVL_Height(root->left) - AVL_Height(root->right);
	if (balance > 1)
	{
		if (AVL_Height(root->left->left) < AVL_Height(root->left->right))
			root->left = rotate_left(root->left);
		return rotate_right(root);
	}
	if (balance < -1)
	{
		if (AVL_Height(root->right->right) < AVL_Height(root->right->left))
			root->right = rotate_right(root->right);
		return rotate_left(root);
	}
	return root;
}

static AVLNode *insert_node(AVLNode *root, int value, int *status)
{
	if (root == NULL)
	{
		AVLNode *node = malloc(sizeof(*node));
		if (node == NULL)
		{
			*status = ERROR_MEMORY_ALLOC;
			return NULL;
		}
		node->data = value;
		node->height = 1;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	if (value < root->data) root->left = insert_node(root->left, value, status);
	else if (value > root->data) root->right = insert_node(root->right, value, status);
	else
	{
		*status = ERROR_INDEX;
		return root;
	}
	if (*status != SUCCESS_TRUE) return root;
	return rebalance(root);
}

int AVL_Insert(AVLNode **root, int value)
{
	int status = SUCCESS_TRUE;
	if (root == NULL) return ERROR_NULL_PTR;
	*root = insert_node(*root, value, &status);
	return status;
}

AVLNode *AVL_Search(AVLNode *root, int value)
{
	if (root == NULL || root->data == value) return root;
	return value < root->data ? AVL_Search(root->left, value) : AVL_Search(root->right, value);
}

static AVLNode *delete_node(AVLNode *root, int value, int *status)
{
	AVLNode *successor;
	if (root == NULL)
	{
		*status = ERROR_EMPTY;
		return NULL;
	}
	if (value < root->data) root->left = delete_node(root->left, value, status);
	else if (value > root->data) root->right = delete_node(root->right, value, status);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			AVLNode *replacement = root->left != NULL ? root->left : root->right;
			free(root);
			return replacement;
		}
		successor = root->right;
		while (successor->left != NULL) successor = successor->left;
		root->data = successor->data;
		root->right = delete_node(root->right, successor->data, status);
	}
	if (*status != SUCCESS_TRUE) return root;
	return rebalance(root);
}

int AVL_Delete(AVLNode **root, int value)
{
	int status = SUCCESS_TRUE;
	if (root == NULL) return ERROR_NULL_PTR;
	*root = delete_node(*root, value, &status);
	return status;
}

int AVL_Free(AVLNode *root)
{
	if (root == NULL) return SUCCESS_TRUE;
	AVL_Free(root->left);
	AVL_Free(root->right);
	free(root);
	return SUCCESS_TRUE;
}
