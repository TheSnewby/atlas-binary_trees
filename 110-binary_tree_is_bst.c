#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid BST
 * @tree: root node
 *
 * Return: 1 if valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left_return = 1, right_return = 1;

	if (!tree)
		return (0);

	if (tree->left)
	{
		if (tree->left->n < tree->n)
			left_return = binary_tree_is_bst(tree->left);
		else
			return (0);
	}
	if (tree->right)
	{
		if (tree->right->n > tree->n)
			right_return = binary_tree_is_bst(tree->right);
		else
			return (0);
	}
	return (left_return * right_return);
}
