#include "binary_trees.h"
/**
 * binary_tree_size-function that return the size of a tree
 * @tree:tree
 * Return:tree size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0, r = 0, i = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		i = binary_tree_size(tree->left);
		r = binary_tree_size(tree->right);
		size = r + i + 1;
	}
	return (size);
}
