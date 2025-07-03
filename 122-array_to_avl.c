#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: array of numbers
 * @size: size of the array
 *
 * Return: pointer to the root node, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	int i;
	avl_t *tree;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (!avl_insert(&tree, array[i]))
			return (NULL);
	}

	return (tree);
}
