#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * count_occurences - Counts the occurences of each value in the array
 * @array: Pointer to the array
 * @size: Size of the array
 * @min: Minimum value in the array
 * @count: Pointer to the count array
 */
void count_occurences(const int *array, size_t size, int min, int *count)
{
	for (size_t i = 0; i < size; i++)
		count[array[i] - min]++;
}

/**
 * build_sorted_array - Builds the sorted array
 * @array: Pointer to the array
 * @size: Size of the array
 * @min: Minimum value in the array
 * @count: Pointer to the count array
 */
void build_sorted_array(int *array, size_t size, int min, const int *count)
{
	int idx = 0;

	for (int i = 0; i < size; i++)
	{
		while (count[i] > 0)
		{
			array[idx++] = i + min;
			count[i]--;
		}
	}
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 * @array: Array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	int max = array[0];
	int min = array[0];
	int range;
	int *count;
	int i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
		else if (array[i] < min)
			min = array[i];
	}

	range = max - min + 1;

	count = malloc(sizeof(int) * range);
	if (count == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for count array.\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < range; i++)
		count[i] = 0;

	count_occurences(array, size, min, count);

	print_array(count, range);

	build_sorted_array(array, size, min, count);

	free(count);
}

