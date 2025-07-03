#include "binary_trees.h"
/**
 * avl_search - binary search for insertion location
 * @tree: node to search
 * @value: value to find
 *
 * Return: parent node of insertion location
 */
avl_t *avl_search(avl_t **tree, int value)
{
	if (((*tree)->left->n > value) && ((*tree)->right->n < value))
		return ((*tree));

	if ((*tree)->n < value)
		return (avl_search((*tree)->left, value));
	else if ((*tree)->n > value)
		return (avl_search((*tree)->right, value));
	else
		return (NULL);
}

/**
 * avl_insert - a function that inserts a vlaue in an AVL Tree
 * @tree: double pointer to the root node
 * @value: value to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance_fac;
	avl_t *parent_at_insert;
	avl_t *new_node;

	if (!(*tree))
	{
		new_node = (avl_t *)malloc(sizeof(avl_t));
		if (!new_node)
			return (NULL);
		new_node->n = value;
		new_node->parent = NULL;
		new_node->left = NULL;
		new_node->right = NULL;
		return (new_node);
	}

	parent_at_insert = avl_search((*tree), value);
	if (value < parent_at_insert->n)
		new_node = binary_tree_insert_left(parent_at_insert, value);
	else
		new_node = binary_tree_insert_right(parent_at_insert, value);

	balance_fac = binary_tree_balance((*tree));

	if (balance_fac < 1)
		binary_tree_rotate_right((*tree));
	else if (balance_fac > 1)
		binary_tree_rotate_left((*tree));

	return (new_node);
}
