#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * is_palindrome - Checks if a singly linked list is a palindrome or not.
 * @head: pointer to the list's head.
 * Return: 1 if it's a palindrome, otherwise 0.
 */
int is_palindrome(listint_t **head)
{
	int len = 0, i = 0, c;
	listint_t *start, *end;

	if (!head)
		return (0);

	if (!(*head))
		return (1);

	end = *head;
	start = *head;
	len += 1;

	while (end->next)
	{
		end = end->next;
		len++;
	}

	c = len / 2;

        while (i <= c)
        {
                if (start->n != end->n)
                        return (0);
                start += 2;
                end -= 2;
		i++;
        }

	return (1);
}
