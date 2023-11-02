#include "binary_trees.h"

/**
 * binary_tree_depth - Measures how far down a node is in binary tree
 *
 * @tree: A pointer to to the node to check the depth for
 *
 * Return: 0 if the tree is NULL
 */


size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
