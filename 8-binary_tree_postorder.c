#include "binary_trees.h"

/**
 * binary_tree_inorder - traverses a tree in order
 * @tree: tree
 * @func: passed function
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return;
	if (tree->left)
		binary_tree_postorder(tree->left, func);
	if (tree->right)
		binary_tree_postorder(tree->right, func);
	if (func)
		func(tree->n);
}
