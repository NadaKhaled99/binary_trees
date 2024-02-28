#include "binary_trees.h"
/**
 * binary_trees_ancestor - function that checks an ancestor
 * @first: 1st node
 * @second: 2nd node
 * Return:node of the ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *b, *w;
	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	b = first->parent;
	w = second->parent;
	if (b == NULL || first == w || (!b->parent && w))
	{
		return (binary_trees_ancestor(first, w));
	}
	else if (q == NULL || p == second || (!q->parent && p))
	{
		return (binary_trees_ancestor(p, second));
	}
	return (binary_trees_ancestor(p, q));
}
