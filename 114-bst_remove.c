#include "binary_trees.h"

bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove(bst_t *root, int value);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *inorder_successor(bst_t *root);

/**
 * bst_remove - Removes a node with a specific value
 *	from a Binary Search Tree(BST)
 *
 * @root: A pointer to the root node of the Binary Search Tree
 * @value: The value to remove from BST
 *
 * Return: A pointer to the new root node of BST
 */


bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}

/**
 * bst_remove_recursive - Removes a node from a BST recursively
 * @root: A pointer to the root node of a BST
 * @node: Current node to be examined
 * @value: The value to remove from the BST
 *
 * Return: A pointer to the root after deletion
 */


bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_delete - Deletes a node from the BST
 * @root: A pointer of the BST the root
 * @node: A pointer to the node to delete from a BST
 *
 * Return: The pointer to the new root node after the deletion
 */


bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* children or right-child only */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* Two children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * inorder_successor - Returns a binary search tree minimum value
 * @root: A pointer to the root node of the BST to be searched
 *
 * Return: The minimum value in a @tree
 */


bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}
