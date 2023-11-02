#include "binary_trees.h"

/**
 * binary_tree_preorder - traverses the binary tree utilising pre-order traversal
 *
 * @tree: A pointer that points to the root node of tree to be traversed
 * @func: A pointer that points to a function to call for each node
 */


void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
