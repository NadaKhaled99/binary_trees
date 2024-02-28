#include "binary_trees.h"
/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree:tree
 * Return:height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t i = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			i = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((i > r) ? i : r);
	}
}
