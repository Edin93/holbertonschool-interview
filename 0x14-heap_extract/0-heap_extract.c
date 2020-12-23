#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 *
 * @root: A double pointer to the root node of the heap.
 *
 * Return: The value stored in the root node otherwise return 0.
*/
int heap_extract(heap_t **root)
{
	return ((*root)->n);
}
