#include "binary_trees.h"
/**
 * binary_tree_insert_right -add node in the right of the parent
 * if it exists it move down one level and add the new node first
 * @parent: parent of the specific node
 * @value: value of node
 * Return: NULL if it fails or the new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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
	if (parent->right != NULL)
	{
		nnew_node->right = parent->right;
		parent->right->parent = nnew_node;
	}
	parent->right = nnew_node;
	return (nnew_node);
}
