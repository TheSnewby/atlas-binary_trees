#include "binary_trees.h"

size_t btb_helper(const binary_tree_t *tree);
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: root node of the tree
 *
 * Return: height left - height right, 0 if NULL or balanced
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (brb_helper(tree->left) - btb_helper(tree->right));
}

/**
 * btb_helper - measures the height of a binary tree
 * @tree: root node of tree
 *
 * Return: height of tree, 0 if NULL
 */
size_t btb_helper(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0, height;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = btb_helper(tree->left);
	if (tree->right)
		height_r = btb_helper(tree->right);
	height = height_l >= height_r ? height_l : height_r;

	if (!tree->left && !tree->right)
		return (height);
	return (1 + height);
}