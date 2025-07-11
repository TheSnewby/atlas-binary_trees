#include "binary_trees.h"

#include "binary_trees.h"

/**
 * bst_insert_balancer - balances during the bst_insert()
 * @tree: double pointer to a node
 * @value: value being added
 */
void bst_insert_balancer(bst_t **tree, int value)
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

	bst_insert_balancer(tree, value);

	return (new_node);
}
