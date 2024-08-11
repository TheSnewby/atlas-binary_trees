#include "binary_trees.h"

binary_tree_t *binary_tree_sibling_helper(binary_tree_t *parent,
				binary_tree_t *original_node);
/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: node
 *
 * Returns: pointer to sibling node, or NULL otherwise
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node)
		return (NULL);
	if (!node->parent)
		return (NULL);
	return (binary_tree_sibling_helper(node->parent, node));
}

/**
 * binary_tree_sibling_helper - finds possible sibling
 * @parent: parent of original node
 * @original_node: original node to find sibling of
 *
 * Return: sibling or NULL
 */
binary_tree_t *binary_tree_sibling_helper(binary_tree_t *parent,
				binary_tree_t *original_node)
{
	if (parent->left && parent->left != original_node)
		return (parent->left);
	else if (parent->right && parent->right != original_node)
		return (parent->right);
	return (NULL);
}
