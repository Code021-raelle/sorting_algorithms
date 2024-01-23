#include "sort.h"
#include <stdlib.h>

void swap_sort(listint_t **list, listint_t *end, int *swapped)

/**
 * swap_sort - Performs a bubble sort pass on the list
 * @list: Double pointer to the first element of the list
 * @end: Pointer to the end of the list
 * @swapped: Pointer to a flag indicating whether a swap occurred
 */
void swap_sort(listint_t **list, listint_t *end, int *swapped)
{
	listint_t *start = *list;
	int temp;

	while (start->next != end)
	{
		if (start->n > start->next->n)
		{
			temp = start->n;
			start->n = start->next->n;
			start->next->n = temp;
			*swapped = 1;
		}
		start = start->next;
	}
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using Cocktail Shaker Sort
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = *list;
	listint_t *end;
	int swapped;
	int temp;

	if (start == NULL)
		return;

	do {
		swapped = 0;
		end = NULL;

		swap_sort(&start, end, &swapped);

		if (!swapped)
			break;

		swapped = 0;
		start = *list;
		end = NULL;
		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				temp = start->n;
				start->n = start->next->n;
				start->next->n = temp;
				swapped = 1;
			}
			start = start->next;
		}

		print_list(*list);
	} while (swapped);
}

