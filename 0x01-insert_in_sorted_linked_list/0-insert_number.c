#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lists.h"

/**
 * insert_node - inserts a number in a sorted linked list.
 * @head: pointer to the head of the list.
 * @number: the number to be inserted.
 * Return: the address of the new node, or NULL if it failed.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *p;

	if (head == NULL || *head == NULL)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	p = *head;
	new->n = number;
	if (p->n > number)
	{
		new->next = p;
		*head = new;
		return (new);
	}
	while (p->next != NULL && p->next->n < number)
		p = p->next;
	new->next = p->next;
	p->next = new;
	return (new);
}
