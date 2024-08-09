#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to the root of the tree to be deleted
 */

void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *temp = NULL, *sacrifice = NULL;
	char sacrifice_LR = 'a';

	if (tree == NULL)
		return;

	temp = tree;
	while (tree != NULL)
	{
		if (temp->left)  /* if left child exists */
		{
			sacrifice_LR = 'l';
			temp = temp->left;
		}
		else if (temp->right) /* if right child exists */
		{
			sacrifice_LR = 'r';
			temp = temp->right;
		}
		else /* if neither exists */
		{
			if (temp == tree) /* if at root */
			{
				free(temp);
				temp = NULL;
				return;
			}
			sacrifice = temp;
			temp = temp->parent;
			free(sacrifice); /* free node */
			sacrifice = NULL;

			/* set parent's child to NULL */
			if (sacrifice_LR == 'l')
				temp->left = NULL;
			else if (sacrifice_LR == 'r')
				temp->right = NULL;
			sacrifice_LR = 'a';
		}
	}
}
