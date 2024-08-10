#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * full means every node has either 0 or 2 children
 * @tree: node of tree
 *
 * Return: 1 if full, otherwise 0
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	/* check if no children */
	if (!tree->left && !tree->right)
		return (1);
	/* check if there are two children*/
	if ((tree->left && tree->right))
	{
		return (1 * binary_tree_is_full(tree->left) *
				binary_tree_is_full(tree->right));
	}
	return (0); /* not full */
}
