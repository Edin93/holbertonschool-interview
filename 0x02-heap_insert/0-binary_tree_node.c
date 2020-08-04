#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: pointer of the parent node of the node to create.
 * @value: value to put in the new node.
 * Return: the pointer to the new node or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->right = NULL;
	new->left = NULL;
	new->parent = NULL;
	if (parent)
		new->parent = parent;
	return (new);
}
