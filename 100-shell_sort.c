#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int temp;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}

