#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotates a binary tree to the left
 * @tree: the passed tree or subtree
 *
 * Return: new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *oldrt, *newrt, *child, *grandparent;

	if (!tree || !tree->right)
		return (NULL);

	oldrt = tree;
	newrt = tree->right;
	child = tree->right->left;
	grandparent = tree->parent;

	newrt->parent = grandparent; /* switch parents */
	oldrt->parent = newrt;

	if (grandparent) /* adjust grandparent's child */
	{
		if (grandparent->left == oldrt)
			grandparent->left = newrt;
		else
			grandparent->right = newrt;
	}

	oldrt->right = child; /* modify relationships with child */
	if (child)
		child->parent = oldrt;

	newrt->left = oldrt;


	return (newrt);
}
