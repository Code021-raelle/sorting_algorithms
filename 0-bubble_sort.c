#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * bubble_sort - Function to perform bubble sort on an array
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}

