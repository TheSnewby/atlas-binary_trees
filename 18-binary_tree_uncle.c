#include "binary_trees.h"

binary_tree_t *btu_helper(binary_tree_t *grandparent, binary_tree_t *parent);
/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: node to look for uncle
 *
 * Return: uncle or NULL otherwise
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);
	if (node->parent)
		if (node->parent->parent)
			return (btu_helper(node->parent->parent, node->parent));
	return (NULL);
}

/**
 * btu_helper - uncle finder
 * @grandparent: grandparent of original node
 * @parent: parent of original node
 *
 * Return: uncle or NULL
 */
binary_tree_t *btu_helper(binary_tree_t *grandparent, binary_tree_t *parent)
{
	if (grandparent->left && grandparent->left != parent)
		return (grandparent->left);
	else if (grandparent->right && grandparent->right != parent)
		return (grandparent->right);
	return (NULL);
}
