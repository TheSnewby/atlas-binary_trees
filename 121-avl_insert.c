#include "binary_trees.h"

/**
 * avl_insert_balancer - balances during the avl_insert()
 * @tree: double pointer to a node
 * @value: value being added
 */
void avl_insert_balancer(avl_t **tree, int value)
{
	int	balance = binary_tree_balance(*tree);

	/* LL Case */
	if (balance > 1 && value < (*tree)->left->n)
	{
		*tree = binary_tree_rotate_right(*tree);
		if (*tree && (*tree)->parent == NULL)
			(*tree)->parent = NULL;
	}

	/* RR Case */
	else if (balance < -1 && value > (*tree)->right->n)
	{
		*tree = binary_tree_rotate_left(*tree);
		if (*tree && (*tree)->parent == NULL)
			(*tree)->parent = NULL;
	}

	/* LR Case */
	else if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		if ((*tree)->left)
			(*tree)->left->parent = *tree;
		*tree = binary_tree_rotate_right(*tree);
		if (*tree && (*tree)->parent == NULL)
			(*tree)->parent = NULL;
	}

	/* RL Case */
	else if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		if ((*tree)->right)
			(*tree)->right->parent = *tree;
		*tree = binary_tree_rotate_left(*tree);
		if (*tree && (*tree)->parent == NULL)
			(*tree)->parent = NULL;
	}
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
	avl_t *new_node = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		new_node = avl_insert(&((*tree)->left), value);
		if (new_node && (*tree)->left)
			(*tree)->left->parent = *tree;
	}
	else if (value > (*tree)->n)
	{
		new_node = avl_insert(&((*tree)->right), value);
		if (new_node && (*tree)->right)
			(*tree)->right->parent = *tree;
	}
	else
		return (NULL);

	if (new_node == NULL)
		return (NULL);

	return (new_node);
}
