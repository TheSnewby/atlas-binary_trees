#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to the root of the tree to be deleted
 */

void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *temp = NULL, *sacrifice = NULL;

	if (tree == NULL)
		return;

	temp = tree;
	while (tree != NULL)
	{
		if (temp->left)
			temp = temp->left;
		else if (temp->right)
			temp = temp->right;
		else if (!temp->left && !temp->right)
		{
			if (temp == tree)
			{
				free(temp);
				temp = NULL;
			}
			sacrifice = temp;
			temp = temp->parent;
			free(sacrifice);
			sacrifice = NULL;
		}
	}
}
