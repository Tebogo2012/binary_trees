#include "binary_trees.h"

avl_t *avl_remove(avl_t *root, int value);
bst_t *bst_remove(bst_t *root, int value);
int remove_type(bst_t *root);
int successor(bst_t *node);
void bal(avl_t **tree);

/**
 * avl_remove - Removes the node from an AVL tree
 *
 * @root: A pointer to the root node of A tree for removin NODE
 * @value: A value to be removed in the tree
 *
 * Return: A pointer to the new root node of the tree after
 *         removing the desired value, and after rebalancing
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);

	return (root_a);
}

/**
 * bst_remove - Remove the node from a Binary Search Tree BST tree
 *
 * @root: The root of the tree
 * @value: Node with this value to be removed
 *
 * Return: The tree to change
 */

bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * remove_type - The unction that removes the node depending of its children
 *
 * @root: The node to be removed
 *
 * Return: 0 if it has no children or other value if it has
 */

int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * successor - Obtain the next successor i mean the min node in a right subtree
 *
 * @node: The tree to be examined
 *
 * Return: The min value ofa tree
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}

/**
 * bal - Count balance factor of a AVL
 *
 * @tree: The tree to go through
 *
 * Return: The balanced factor
 */

void bal(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
