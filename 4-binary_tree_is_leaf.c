#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: node
 *
 * Return: 1 if node, otherwise 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
	return (1);
	return (0);
}
