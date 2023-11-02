#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from the array
 *
 * @array: the pointer that points to the first element of array to convert
 * @size: A number of element in array
 *
 * Return: The pointer to the root node of the created AVL tree, NULL on failure
 */


avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t index, jndex;

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		for (jndex = 0; jndex < index; jndex++)
		{
			if (array[jndex] == array[index])
				break;
		}
		if (jndex == index)
		{
			if (avl_insert(&tree, array[index]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
