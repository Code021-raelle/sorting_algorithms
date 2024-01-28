#include "sort.h"
#include <stdio.h>

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using Cocktail Shaker Sort
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;
	listint_t *tmp;

	if (list == NULL || *list == NULL)
		return;

	do
	{
		swapped = 0;
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				if (current->prev != NULL)
					current->prev->next = current->next;
				else
					*list = current->next;

				current->next->prev = current->prev;
				current->prev = current->next;
				current->next = current->next->next;

				if (current->next != NULL)
					current->next->prev = current;

				current->prev->next = current;
				swapped = 1;
				print_list(*list);
			}
		}

		if (swapped == 0)
			break;

		swapped = 0;
		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				if (current->next != NULL)
					current->next->prev = current->prev;
				else
					current->prev->next = NULL;

				current->prev->next = current->next;
				current->next = current->prev;
				current->prev = current->prev->prev;

				if (current->prev != NULL)
					current->prev->next = current;

				swapped = 1;
				print_list(*list);
			}
		}
	} while (swapped);
}

