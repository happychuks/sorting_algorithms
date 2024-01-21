#include "sort.h"
#include <stdio.h>

/**
* swap_nodes - Swaps two nodes in a doubly linked list
* @list: Pointer to the head!
* @n1: Pointer to the first node
* @n2: Pointer to the second node
*/
void swap_nodes(listint_t **list, listint_t **n1, listint_t **n2)
{
	listint_t *temp;

	temp = (*n1)->prev;
	(*n1)->prev = (*n2)->prev;
	(*n2)->prev = temp;

	if ((*n1)->prev)
		(*n1)->prev->next = *n1;
	else
		*list = *n1;

	temp = (*n1)->next;
	(*n1)->next = (*n2)->next;
	(*n2)->next = temp;

	if ((*n1)->next)
		(*n1)->next->prev = *n1;

	if ((*n2)->next)
		(*n2)->next->prev = *n2;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

/**
* cocktail_sort_list - Sorts a doubly linked list!
* @list: Pointer to the head!
*/
void cocktail_sort_list(listint_t **list)
{
	int swapped;

	listint_t *current = NULL;
	listint_t *last_swapped = NULL;
	listint_t *end = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;

		for (current = *list; current->next != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, &(current->next));
				swapped = 1;
				last_swapped = current;
			}
		}

		if (!swapped)
			break;

		end = last_swapped;

		swapped = 0;

		for (current = last_swapped->prev; current != NULL; current = current->prev)
		{
			if (current->prev && current->prev->n > current->n)
			{
				swap_nodes(list, &(current->prev), &current);
				swapped = 1;
				last_swapped = current;
			}
		}
	} while (swapped);
}
