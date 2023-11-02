#include "binary_trees.h"

int binary_tree_is_bst(const binary_tree_t *tree);
int is_bst_helper(const binary_tree_t *tree, int low, int high);

/**
 * binary_tree_is_bst - Examines if a binary tree is a valid BST
 *
 * @tree: A pointer to a root node of the tree to be examined
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */


int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_helper - The helper function to examine
 *	if a binary tree is a valid BST
 *
 * @tree: A pointer to the root node of the tree be examined
 * @low: A value of the smallest node
 * @high: A largest node visited thus far
 *
 * Return: If tree is a valid BST, 1, otherwise, 0
 */


int is_bst_helper(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		return (is_bst_helper(tree->left, low, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, high));
	}

	return (1);
}
