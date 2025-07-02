#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotates a binary tree to the left
 * @tree: the passed tree or subtree
 *
 * Return: new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (!tree)
		return (NULL);

	tree->right->parent = tree->parent; /* assign old root's parent to new root's parent */
	tree->parent = tree->right; /* assign old root's parent to new root */

	if (tree->right->left)
	{
		tree->right->left->parent = tree; /* assign new root's L-child's parent to old root */
		tree->right = tree->right->left; /* assign old root's R-child to new root's old L-child */
	}

	tree->right->left = tree; /* change new root's left to old root */

	return tree->parent;
}
