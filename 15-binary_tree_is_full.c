#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: node of tree
 *
 * Return: 1 if full, otherwise 0
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	/* also check for empty before calling child */
	if ((tree->left && tree->right) || !(tree->left && tree->right))
	{
		if (tree->left && tree->right)
			return (1 * binary_tree_is_full(tree->left) *
			binary_tree_is_full(tree->right));
		else
			return (1);
	}
	return (0);
}
