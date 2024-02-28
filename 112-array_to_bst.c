#include "binary_trees.h"
/**
 * array_to_bst-turns an array to a BST tree
 * @array:array to turns to BST tree
 * @size:size of array
 * Return:tree from array
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t j = 0;
	bst_t *root;
	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (; j < size; j++)
	{
		if (j == 0)
		{
			bst_insert(&root, array[j]);
		}
		else
		{
			bst_insert(&root, array[j]);
		}
	}
	return (root);
}
