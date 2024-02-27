#include "binary_trees.h"
/**
 * binary_tree_insert_left-add node in the left of the parent
 * if it exists it move down one level and add the new node first
 * @parent:parent of the specified node
 * @value:value of the node
 * Return:NULL if it fails or the new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *nnew_node;
	if (parent == NULL)
	{
		return (NULL);
	}

	nnew_node = binary_tree_node(parent, value);
	if (nnew_node == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		nnew_node->left = parent->left;
		parent->left->parent = nnew_node;
	}
	parent->left = nnew_node;
	return (nnew_node);
}
