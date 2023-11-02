#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the node uncle
 *
 * @node: A pointer to a node to observe the uncle
 *
 * Return: NULL if node is NULL, or node has no uncle
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	return (node->parent->parent->left);
}
