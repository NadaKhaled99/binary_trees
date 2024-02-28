#include "binary_trees.h"
/**
 * binary_tree_nodes-function that returns # of nodes in a tree with children
 *@tree:tree
 *@Return: number of nodes with children
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{

	size_t  nnode = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		nnode += ((tree->left || tree->right) ? 1 : 0);
		nnode += binary_tree_nodes(tree->left);
		nnode += binary_tree_nodes(tree->right);
		return (nnode);
	}
}
