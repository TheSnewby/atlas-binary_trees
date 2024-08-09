#include "binary_trees.h"

size_t bth_helper(const binary_tree_t *tree, size_t height);

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: root node of tree
 *
 * Return: height of tree, 0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	if (!tree)
		return (0);

	return (bth_helper(tree, height));
}

/**
 * bth_helper - recursive function to find height
 * @tree: node of tree
 * @height: height
 *
 * Return: height
 */
size_t bth_helper(const binary_tree_t *tree, size_t height)
{
	size_t height_L = 0, height_R = 0;

	if (tree->left)
		height_L = bth_helper(tree->left, 1 + height);
	if (tree->right)
		height_R = bth_helper(tree->right, 1 + height);
	return (height_L >= height_R ? height_L : height_R);
}
