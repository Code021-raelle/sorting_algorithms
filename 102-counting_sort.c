#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * @array: Array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	if (size == 0) return;

	int max = array[0];

	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	int *count = malloc((max + 1) * sizeof(int));

	for (int i = 0; i <= max; i++)
	{
		count[i] = 0;
	}

	for (size_t i = 0; i < size; i++)
	{
		count[array[i]]++;
	}

	print_array(count, max + 1);

	for (int i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];
	}

	int *output = malloc(size * sizeof(int));

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (size_t i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	free(count);
	free(output);
}

