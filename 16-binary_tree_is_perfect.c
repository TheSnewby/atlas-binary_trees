#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
int perfect_helper(const binary_tree_t *node, int height, int level_tracker);
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * perfect being that leafs are on the same level and every node execpt leaves
 * have two children
 * @tree: root node
 *
 * Return: 1 if perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (perfect_helper(tree, (int)binary_tree_height(tree), 0));
}

/**
 * perfect_helper - recursively checks for perfection
 * @node: node on the tree
 * @height: lowest level of tree
 * @level_tracker: tracks current level away from root
 *
 * Return: 1 if perfect, otherwise 0
 */
int perfect_helper(const binary_tree_t *node, int height, int level_tracker)
{
	/* check if leaves-only at lowest level  */
	if (level_tracker == height && (!node->left && !node->right))
		return (1);
	/* check if there are two children */
	if ((node->left && node->right))
	{
		return (1 * perfect_helper(node->left, height, level_tracker + 1) *
			perfect_helper(node->right, height, level_tracker + 1));
	}
	return (0); /* not perfect */
}
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: root node of tree
 *
 * Return: height of tree, 0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0, height;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = binary_tree_height(tree->left);
	if (tree->right)
		height_r = binary_tree_height(tree->right);
	height = height_l >= height_r ? height_l : height_r;

	if (!tree->left && !tree->right)
		return (height);
	return (1 + height);
}
