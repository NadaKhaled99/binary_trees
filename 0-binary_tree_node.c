#include "binary_trees.h"
/**
 * binary_tree_node-create binary node
 * @parent:parent node
 * @value:value of node
 * Return:new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *nnew_node;
nnew_node = malloc(sizeof(binary_tree_t));
if (nnew_node == NULL)
{
return (NULL);
}
nnew_node->n = value;
nnew_node->parent = parent;
nnew_node->left = NULL;
nnew_node->right = NULL;
return (nnew_node);
}
