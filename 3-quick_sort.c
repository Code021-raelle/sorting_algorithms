#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * partition - Partitions the array around a pivot
 * @arr: Array to be partitioned
 * @low: Starting index of the array
 * @high: Ending index of the array
 *
 * Return: Index of the pivot element
 */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/**
 * quick_sort - Sorts an array of integers in ascending order using QuickSort
 * @arr: Array to be sorted
 * @low: Starting index of the array
 * @high: Ending index of the array
 */
void quick_sort(int array[], size_t size)
{
	quick_sort_recursie(array, 0, size - 1);
}

/**
 * quick_sort_recursive - Recursively sorts an array of integers
 * @array: Array to be sorted
 * @low: Starting index of the array
 * @high: Ending index of the array
 */
void quick_sort_recursive(int array[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

