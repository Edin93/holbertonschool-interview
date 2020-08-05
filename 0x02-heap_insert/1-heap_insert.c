#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: a double pointer to the root node of the Heap.
 * @value: the value store in the node to be inserted.
 * Return: a pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *p;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = (heap_t *)binary_tree_node(NULL, value);
		return (*root);
	}
	new = (heap_t *)binary_tree_node(NULL, value);
	p = *root;
	while (p->left && p->right)
	{
		if (p->left && !p->right)
			p = p->right;
		else
			p = p->left;
	}
	if (!p->left && !p->right)
		p->left = new;
	else if (p->left && !p->right)
		p->right = new;
	new->parent = p;
	return (new);
}
