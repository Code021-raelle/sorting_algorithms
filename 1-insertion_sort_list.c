#include "sort.h"

listint_t *sortedInsert(listint_t **head_ref, listint_t *new_node);

/**
 * insertion_sort_list - sorts a list of integers in ascending order
 *
 * @list: double pointer to head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *current = *list;

	while (current != NULL)
	{
		listint_t *next = current->next;

		current->next = NULL;

		sorted = sortedInsert(&sorted, current);

		current = next;
	}

	*list = sorted;
}

/**
 * sortedInsert - inserts a node into a sorted doubly linked list
 *
 * @head_ref: double pointer to head of the list
 * @new_node: node to be inserted
 * Return: void
 */
listint_t *sortedInsert(listint_t **head_ref, listint_t *new_node)
{
	listint_t *current;

	if (*head_ref == NULL || (*head_ref)->n >= new_node->n)
	{
		new_node->next = *head_ref;
		if (*head_ref != NULL)
			(*head_ref)->prev = new_node;
		*head_ref = new_node;
	}
	else
	{
		current = *head_ref;
		while (current->next != NULL && current->next->n < new_node->n)
		{
			current = current->next;
		}
		new_node->next = current->next;
		if (current->next != NULL)
			new_node->next->prev = new_node;
		current->next = new_node;
		new_node->prev = current;
	}
	return (*head_ref);
}

