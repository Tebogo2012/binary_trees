#include "binary_trees.h"

int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - Examine the perfect binary tree
 *
 * @tree: A pointer to the root node of the tree to be examined
 *
 * Return: 0 if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}

/**
 * depth - Calculate the depth of a given
 *         node in binary tree
 * @tree: A pointer to the node to measure the depth of.
 *
 * Return: a node depth
 */

size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Returns the binary tree leaf
 * @tree: A pointer to the root node of the tree
 *
 * Return: A pointer to the first leaf
 */


const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Examine if a binary tree is recursively PERFECT
 * @tree: The pointer to the root node of tree to be checked
 * @leaf_depth: The depth in the binary tree of the one leaf
 * @level: The current node level
 *
 * Return: If a tree is perfect, 1, otherwise 0
 */

int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * is_leaf - Examine if a node is a leaf of a binary tree
 * @node: A pointer to the node tobe checked
 *
 * Return: If a node is a leaf, 1, otherwise, 0
 */

unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}
