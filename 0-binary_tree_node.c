#include "binary_trees.h"

/**
 * binary_tree_node - Creates the node for the binary tree
 *
 * @parent: A pointer that points to the parent of node
 * @value: The value to insert on the new node
 *
 * Return: If fails - NULL else - a pointer that points to a new node
 */


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
