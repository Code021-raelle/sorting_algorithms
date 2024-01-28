#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 * @array: Array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int max = array[0];

	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	int *count = malloc((max + 1) * sizeof(int));

	if (count == NULL)
		return;

	for (int i = 0; i <= max; i++)
		count[i] = 0;

	for (size_t i = 0; 
