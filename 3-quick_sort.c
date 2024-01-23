#include "sort.h"
/**
 * partition - Partitions the array around a pivot
 * @array: Pointer to the array
 * @low: Starting index of the array
 * @high: Ending index of the array
 *
 * Return: Index of the pivot element
 */
size_t partition(int *array, size_t low, size_t high)
{
	int pivot = array[high];
	size_t i = (low - 1);
	size_t j;
	int temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			print_array(array, high - low + 1);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	print_array(array, high - low + 1);

	return (i + 1);
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	size_t pi;

	if (size < 2)
	{
		return;
	}

	pi = partition(array, 0, size - 1);

	quick_sort(array, pi);
	quick_sort(&array[pi + 1], size - pi - 1);
}

