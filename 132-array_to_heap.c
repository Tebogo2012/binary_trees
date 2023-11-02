#include "binary_trees.h"

/**
 * array_to_heap - Constructs a Max Binary Heap tree from the array
 *
 * @array: The pointer to the first element of an array to be converted
 * @size: A number of element in an array
 *
 * Return: The pointer to the root node of the created one, NULL on failure
 */

heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int index;
	heap_t *root = NULL;

	for (index = 0; index < size; index++)
		heap_insert(&root, array[index]);

	return (root);
}i
