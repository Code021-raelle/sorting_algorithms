#include "sort.h"

/**
 * selection_sort - sorts an array of integers in an ascending order
 *
 * @array: pointer to the array to be sorted
 * @size: number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		int min_idx = i;
		
		for (size_t j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			int temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
		}
	}
}

