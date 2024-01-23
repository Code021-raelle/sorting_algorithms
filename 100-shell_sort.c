#include "sort.h"

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

	while ((gap = gap * 3 + 1) <= size)
	{
		for (i = gap; i < size; i += gap)
		{
			int temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}

