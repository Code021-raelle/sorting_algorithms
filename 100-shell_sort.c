#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	int interval = 1;

	while (interval < size)
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{
		for (size_t i = interval; i < size; i++)
		{
			int temp = array[i];
			size_t j;

			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
				print_array(array, size);
			}
			array[j] = temp;
			print_array(array, size);
		}
		interval /= 3;
	}
}

