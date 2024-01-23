#include "sort.h"
#include <stdio.h>

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the QuickSort algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return;

	int pivot = array[size - 1];
	int i = 0;
	int j = size - 1;

	while (i < j)
	{
		while (array[i] <= pivot && i < j)
			i++;
		while (array[j] > pivot)
			j--;

		if (i < j)
		{
			int temp = array[i];

			array[i] = array[j];
			array[j] = temp;

			for (size_t k = 0; k < size; k++)
				printf("%d ", array[k]);
			printf("\n");
		}
	}

	quick_sort(array, i);
	quick_sort(array + i, size - i);
}

