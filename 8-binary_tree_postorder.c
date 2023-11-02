#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverse a binary tree post-order traversal
 *
 * @tree: A pointer that points to the root
 * node of the tree to be traversed
 * @func: A pointer that points to a function for each node
 */


void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
