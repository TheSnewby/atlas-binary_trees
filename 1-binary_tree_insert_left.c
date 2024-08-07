#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: parent node of new node
 * @value: value of new node
 *
 * Return: pointer to new node, NULL otherwise
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (parent == NULL)
		return (NULL);

	new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	/* initialize all but left node */
	new_node->n = value;
	new_node->parent = parent;
	new_node->right = NULL;

	/* check if parent's left node already has an occupant*/
	if (parent->left != NULL)
	{
		new_node->left = parent->left; /* point new node's left at it */
		new_node->left->parent = new_node;
	}
	else
		new_node->left = NULL;
	parent->left = new_node;

	return (new_node);
}
