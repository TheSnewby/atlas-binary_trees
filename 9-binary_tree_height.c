#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: root node of tree
 *
 * Return: height of tree, 0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0, height;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = binary_tree_height(tree->left);
	if (tree->right)
		height_r = binary_tree_height(tree->right);
	height = height_l >= height_r ? height_l : height_r;

	if (!tree->left && !tree->right)
		return (height);
	return (1 + height);
}
