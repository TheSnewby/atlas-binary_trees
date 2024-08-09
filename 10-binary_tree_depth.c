#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure depth
 *
 * Return: depth, or 0 if tree is NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t height = 0;

	if (!tree)
		return (0);
	if (tree->parent)
		return (1 + binary_tree_depth(tree->parent));
	return (1);
}
