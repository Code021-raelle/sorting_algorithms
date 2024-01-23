#include "sort.h"

/**
 * swap - Swaps two nodes in a doubly linked list
 * @a: Node to be swapped
 * @b: Node to be swapped
 */
void swap(listint_t **a, listint_t **b)
{
	listint_t *temp = *a;
	*a = *b;
	*b = temp;
	print_list(list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using Cocktail Shaker Sort
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = *list;
	listint_t *end = NULL;
	listint_t *temp = NULL;
	int swapped = 1;

	if (list == NULL || *list == NULL)
	{
		return;
	}

	while (swapped)
	{
		swapped = 0;
		temp = start;

		while (temp->next != end)
		{
			if (temp->n > temp->next->n)
			{
				swap(&temp, &(temp->next));
				swapped = 1;
			}
			temp = temp->next;
		}

		end = temp;

		while (temp->prev != start)
		{
			temp = temp->prev;
			if (temp->n > temp->prev->n)
			{
				swap(&temp, &(temp->prev));
				swapped = 1;
			}
		}

		start = temp->prev;
	}
}

