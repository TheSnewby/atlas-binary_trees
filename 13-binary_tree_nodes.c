#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: root node of tree
 *
 * Return: number of parents in tree, 0 if tree is NULL or there are no parents
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t parent = 0;

	if (!tree)
		return (0);
	if (tree->left || tree->right)
		parent = 1;
	return (parent + binary_tree_nodes(tree->left) +
	binary_tree_nodes(tree->right));
}
