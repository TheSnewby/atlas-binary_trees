#include "binary_trees.h"

/**
 * btib_recursive - Binary Tree Is BST recursive call
 * @tree: root node
 * @min: minimum allowed R Value
 * @max: maximum allowed L Value
 *
 * Return: 1 if valid BST, 0 otherwise
 */
int btib_recursive(const binary_tree_t *tree, int min, int max)
{
	int left_return = 1, right_return = 1;

	if (tree->left)
	{
		if ((tree->left->n < tree->n) && (tree->left->n < max))
			left_return = btib_recursive(tree->left, min, tree->left->n);
		else
			return (0);
	}
	if (tree->right)
	{
		if ((tree->right->n > tree->n) && (tree->right->n > min))
			right_return = btib_recursive(tree->right, tree->right->n, max);
		else
			return (0);
	}
	return (left_return * right_return);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid BST
 * @tree: root node
 *
 * Return: 1 if valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int min, max;

	if (!tree)
		return (0);

	min = tree->n;
	max = tree->n;

	if (tree->left && (tree->left->n < tree->n))
		min = tree->left->n;
	else
		return (0);
	if (tree->right && (tree->right->n > tree->n))
		max = tree->right->n;
	else
		return (0);

	return (btib_recursive(tree, min, max));

}
