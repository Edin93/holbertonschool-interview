#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

#define CMPZERO(n) ((n >= 0) ? (n) : (0))

/**
 * get_queue - Get a queue representation of the Binary tree.
 * @root: pointer to the Binary tree root.
 * @q: pointer to the queue to fill.
 */
void get_queue(heap_t **root, heap_t **q)
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
}

/**
 * insert - Inserts a value into a Max Binary Heap.
 * @q: a double pointer to the root node of the Heap.
 * @new: the new node to be inserted.
 * @len: number of nodes in the tree.
 */
void insert(heap_t *q[], heap_t *new, int len)
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
}

/**
 * swap - swaps 2 nodes from the same subtree.
 * @p: parent node of a subtree.
 * @c: child node of a subtree.
 * Return: pointer to newly swapped node.
 */
heap_t *swap(heap_t *p, heap_t *c)
{
	int n;

	n = p->n;
	p->n = c->n;
	c->n = n;
	return (p);
}

/**
 * heapify - recursively max heapify a node at i within its children.
 * @root: root.
 * @q: nodes queue.
 * @len: number of nodes in the tree.
 * @i: index of the subtree to max heapify.
 * @tmp: pointer to the newly placed node.
 */
void heapify(heap_t **root, heap_t **q, int len, int i, heap_t **tmp)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < len && q[left]->n > q[largest]->n)
		largest = left;

	if (right < len && q[right]->n > q[largest]->n)
		largest = right;

	if (largest != i)
	{
		*tmp = swap(q[i], q[largest]);
		get_queue(root, q);
		if (i / 2 >= 0)
			heapify(root, q, len, i / 2, tmp);
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
	heap_t *new, *q[1024], **tmp;
	int len = 0, i;

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
	q[len] = new;
	len += 1;
	tmp = &new;
	for (i = CMPZERO(len / 2 - 1); i >= 0; i--)
	{
		heapify(root, q, len, i, tmp);
	}
	return (*tmp);
}
