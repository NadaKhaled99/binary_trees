#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"
/**
 * print_t - Stores recursively each level in an array of strings
 * @tree: ptrr to the node to print
 * @offset: offset to printt
 * @depth: Depth of the node
 * @s: Buffer
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char p[6];
	int width, left, right, is_left, j;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(p, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (j = 0; j < width; j++)
		s[depth][offset + left + j] = p[j];
	if (depth && is_left)
	{
		for (j = 0; j < width + right; j++)
			s[depth - 1][offset + left + width / 2 + j] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (j = 0; j < left + width; j++)
			s[depth - 1][offset - width / 2 + j] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}
/**
 * _height - Measures the height of a binary tree
 * @tree: ptr to the node to measures the height
 * Return:height of the tree starting at node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;
	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
/**
 * binary_tree_print-Prints a binary tree
 * @tree: ptr to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **c;
	size_t height, i, j;
	if (!tree)
		return;
	height = _height(tree);
	c = malloc(sizeof(*c) * (height + 1));
	if (!c)
		return;
	for (i = 0; i < height + 1; i++)
	{
		c[i] = malloc(sizeof(**c) * 255);
		if (!c[i])
			return;
		memset(c[i], 32, 255);
	}
	print_t(tree, 0, 0, c);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (c[i][j] != ' ')
				break;
			c[i][j] = '\0';
		}
		printf("%s\n", c[i]);
		free(c[i]);
	}
	free(c);
}
