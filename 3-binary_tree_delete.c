#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to the root of the tree to be deleted
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		if (tree->left)
			binary_tree_delete(tree->left);
		if (tree->right)
			binary_tree_delete(tree->right);
		free(tree);
		tree = NULL;
	}
}
