#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree.
 *
 * @tree: The pointer to the root node of the BST to search.
 * @value: There value to search in the tree.
 *
 * Return: There pointer to the node containing a value equals to value.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));

		return (bst_search(tree->right, value));
	}

	return (NULL);
}
