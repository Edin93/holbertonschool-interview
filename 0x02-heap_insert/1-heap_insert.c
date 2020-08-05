#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * level_traverse - Goes through the binary tree by level.
 * @root: pointer to the Binary tree root.
 * @node: new node to insert.
 */
void level_traverse(heap_t **root, heap_t *node)
{
	heap_t *q[1024], *p;
	int i, j;

	for (i = 0; i < 1024; i++)
	{
		q[i] = NULL;
	}
	p = *root;
	j = 0;
	i = 0;
	q[0] = p;
	while (q[i])
	{
		if ((q[i])->left)
		{
			j++;
			q[j] = (q[i])->left;
		}
		if ((q[i])->right)
		{
			j++;
			q[j] = (q[i])->right;
		}
		i++;
	}
	j = 0;
	while (q[j])
	{
		printf("Q[%d] = %d\n", j, q[j]->n);
		j++;
	}
	printf("node = %d\n", node->n);
}

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
	printf("--------------------------------------------\n");
	level_traverse(root, new);
	printf("--------------------------------------------\n");
	return (new);
}
