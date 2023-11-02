#include "binary_trees.h"

int binary_tree_is_heap(const binary_tree_t *tree);
int check_parent(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes);
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - Examine for a validity of a
 *	binary tree is a valid Max Binary Heap
 *
 * @tree: A pointer to the root node of a tree to examine
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * check_parent - Emamines if parent has a greater value than the childs
 *
 * @tree: The pointer to node
 *
 * Return: 1 if parent has a greater value, 0 otherwise
 */

int check_parent(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * binary_tree_is_complete - Calls to the tree_is_complete function
 *
 * @tree: A tree root
 * Return: 1 if tree is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t cnodes;

	if (tree == NULL)
		return (0);

	cnodes = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, cnodes));
}

/**
 * tree_is_complete - Examines if the tree is complete
 *
 * @tree: Pointer that points to the tree root
 * @i: The node index
 * @cnodes: The number of nodes
 *
 * Return: 1 if tree is complete, 0 otherwise
 */

int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
	if (tree == NULL)
		return (1);

	if (i >= cnodes)
		return (0);

	return (tree_is_complete(tree->left, (2 * i) + 1, cnodes) &&
		tree_is_complete(tree->right, (2 * i) + 2, cnodes));
}


/**
 * binary_tree_size - Count the size of a binary tree
 *
 * @tree: The tree root
 * Return: Size of the tree or 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
