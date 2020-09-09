#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle in it.
 * @list: pointer to the list to check.
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */
int check_cycle(listint_t *list)
{
	listint_t *fast, *slow;

	if (!list || !list->next)
		return (0);

	fast = list;
	slow = fast;
	while (fast && slow && fast->next)
	{
		if (slow->next)
			slow = slow->next;
		if (fast->next->next)
			fast = fast->next->next;
		else
			fast = fast->next;
		if(fast == slow)
			return (1);
	}
	return (0);
}
