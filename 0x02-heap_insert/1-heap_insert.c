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
 * swap - Swaps node place in Max Heap if it's bigger than its parent.
 * @n1: node to swap with b.
 * @n2: node to swap with a.
 */
void swap(heap_t **q, int n1, int n2)
{
	int n;

	n = q[n1]->n;
	q[n1]->n = q[n2]->n;
	q[n2]->n = n;
}

/**
 * heapify - recursively max heapify a node at i within its children.
 * @arr: nodes queue.
 * @len: number of nodes in the tree.
 * @i: index of the subtree to max heapify.
 */
void heapify(heap_t **arr, int len, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < len && arr[left]->n > arr[largest]->n)
		largest = left;

	if (right < len && arr[right]->n > arr[largest]->n)
		largest = right;

	if (largest != i)
	{
		swap(arr, i, largest);
		heapify(arr, len, largest);
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
	for (i = CMPZERO((len / 2) - 1); i >= 0; i--)
		heapify(q, len, i);
	return (new);
}
