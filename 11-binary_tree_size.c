#include "binary_trees.h"

/**
 * binary_tree_size - measures size of a binary tree
 * where size is the number of nodes
 * @tree: node treated as root of the tree
 *
 * Return: size of tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size_l = 0, size_r = 0;

	if (!tree)
		return (0);
	if (tree->left && tree->right)
		return (1 + binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
	else if (tree->right)
		return (1 + binary_tree_size(tree->right));
	else if (tree->left)
		return (1 + binary_tree_size(tree->left));
	else
		return (1);
}
