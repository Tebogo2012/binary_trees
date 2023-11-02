#include "binary_trees.h"

/**
 * binary_tree_insert_right - Load the right child of a node
 *
 * @parent: A pointer to the node for loading the right child in
 * @value: The value to be kept in a new node
 *
 * Return: A pointer to a node that is created,
 * NULL on failure or if parent is NULL
 */


binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
