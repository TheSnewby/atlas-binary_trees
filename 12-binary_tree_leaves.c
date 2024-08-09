#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * where leaves are nodes without children
 * @tree: root of tree
 *
 * Return: number of leaves, 0 if NULL or no leaves
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0;

	if (!tree)
		return (0);
	if (tree->left || tree->right)
		leaf = 1;
	return (leaf + binary_tree_leaves(tree->left) +
	binary_tree_leaves(tree->right));
}
