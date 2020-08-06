#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

#define CMPZERO(n) ((n >= 0) ? (n) : (0))

/**
 * get_queue - Get a queue representation of the Binary tree.
 * @root: pointer to the Binary tree root.
 * @q: pointer to the queue to fill.
 * Return: Queue representation of the Binary tree.
 */
heap_t **get_queue(heap_t **root, heap_t **q)
{
	heap_t *p;
	int i, j;

	for (i = 0; i < 1024; i++)
		q[i] = NULL;
	p = *root;
	j = i = 0;
	q[0] = p;
	while (q[i])
	{
		if ((q[i])->left)
			q[++j] = (q[i])->left;
		if ((q[i])->right)
			q[++j] = (q[i])->right;
		i++;
	}
	return (q);
}

/**
 * insert - Inserts a value into a Max Binary Heap.
 * @q: a double pointer to the root node of the Heap.
 * @new: the new node to be inserted.
 * @len: number of nodes in the tree.
 * Return: a pointer to the inserted node, or NULL on failure.
 */
heap_t *insert(heap_t *q[], heap_t *new, int len)
{
	heap_t *tmp;
	int i = 1, j = 1;

	while (i < len)
		i = i * 2;
	i = 1;
	while (i * 2 < len)
		i = i * 2;
	for (j = CMPZERO((i / 2) - 1); j <= CMPZERO(i - 1); j++)
	{
		tmp = q[j];
		if (!tmp->left)
		{
			tmp->left = new;
			break;
		}
		else if (!tmp->right)
		{
			tmp->right = new;
			break;
		}
	}
	new->parent = tmp;
	return (new);
}

/**
 * swap - Swaps node place in Max Heap if it's bigger than its parent.
 * @node: node to swap.
 */
void swap(heap_t *node)
{
	heap_t *tmp;
	int n;

	tmp = node;
	while (tmp->parent && tmp->n > tmp->parent->n)
	{
		n = tmp->n;
		tmp->n = tmp->parent->n;
		tmp->parent->n = n;
		tmp = tmp->parent;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: a double pointer to the root node of the Heap.
 * @value: the value store in the node to be inserted.
 * Return: a pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *q[1024];
	int len = 0;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = (heap_t *)binary_tree_node(NULL, value);
		return (*root);
	}
	new = (heap_t *)binary_tree_node(NULL, value);
	get_queue(root, q);
	while (q[len])
		len++;
	insert(q, new, len);
	swap(new);
	return (new);
}
