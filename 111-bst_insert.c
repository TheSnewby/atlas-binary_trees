#include "binary_trees.h"

/**
 * bst_insert - insert a node into a BST
 * @tree: double pointer node
 * @value: value to be inserted in a node
 *
 * Return: pointer to created node or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		new_node = bst_insert(&((*tree)->left), value);
		if (new_node && (*tree)->left)
			(*tree)->left->parent = *tree;
	}
	else if (value > (*tree)->n)
	{
		new_node = bst_insert(&((*tree)->right), value);
		if (new_node && (*tree)->right)
			(*tree)->right->parent = *tree;
	}
	else
		return (NULL);

	if (new_node == NULL)
		return (NULL);

	return (new_node);
}
