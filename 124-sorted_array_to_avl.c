#include "binary_trees.h"

/**
 * sorted_array_to_avl_recursive - inserts into tree recursively in order?
 * @tree: double pointer to 
 * 
 */
avl_t *sorted_array_to_avl_recursive(avl_t **tree, int val)
{
	avl_t *new_node = NULL;

	if (!tree)
	{
		new_node = binary_tree_node(NULL, val);
		(*tree) = new_node;
		return (new_node);
	}

	if (val < (*tree)->n)
		return (sorted_array_to_avl_recursive((*tree)->left, val));
	else if (val > (*tree)->n)
		return (sorted_array_to_avl_recursive((*tree)->right, val));
	else
		return (NULL);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: array
 * @size: size of array
 *
 * Return: pointer to the root, NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	size_t i, mid = size / 2;
	avl_t *tree = NULL;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size / 2; i++)
	{
		if (!sorted_array_to_avl_recursive(&tree, array[mid + i]) && !tree)
			return (NULL);
		if (!sorted_array_to_avl_recursive(&tree, array[mid - 1]) && !tree)
			return (NULL);
	}

	return (tree);
}
