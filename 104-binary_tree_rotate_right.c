#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotates a binary tree to the right
 * @tree: the passed tree or subtree
 *
 * Return: new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *oldrt, *newrt, *child, *grandparent;

	if (!tree || !tree->left)
		return (NULL);

	oldrt = tree;
	newrt = tree->left;
	child = tree->left->right;
	grandparent = tree->parent;

	newrt->parent = grandparent; /* switch parents */
	oldrt->parent = newrt;

	if (grandparent) /* adjust grandparent's child */
	{
		if (grandparent->right == oldrt)
			grandparent->right = newrt;
		else
			grandparent->left = newrt;
	}

	oldrt->left = child; /* modify relationships with child */
	if (child)
		child->parent = oldrt;

	newrt->right = oldrt;


	return (newrt);
}
