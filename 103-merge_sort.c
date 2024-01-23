#include "sort.h"

/**
 * merge - Merges two sorted arrays into one sorted array
 * @array: Pointer to the array
 * @left: Starting index of the first sub-array
 * @middle: Ending index of the first sub-array and
 *          starting index of the second sub-array
 * @right: Ending index of the second sub-array
 */
void merge(int *array, int left, int middle, int right)
{
	int size1 = middle - left + 1;
	int size2 = right - middle;

	int *leftArray = malloc(sizeof(int) * size1);
	int *rightArray = malloc(sizeof(int) * size2);

	if (leftArray == NULL || rightArray == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for temporary arrays.\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < size1; i++)
		leftArray[i] = array[left + i];
	for (int i = 0; i < size2; i++)
		rightArray[i] = array[middle + 1 + i];

	int i = 0, j = 0, k = left;

	while (i < size1 && j < size2)
	{
		if (leftArray[i] <= rightArray[j])
		{
			array[k] = leftArray[i];
			i++;
		} else
		{
			array[k] = rightArray[j];
			j++;
		}
		k++;
	}

	while (i < size1)
	{
		array[k] = leftArray[i];
		i++;
		k++;
	}

	while (j < size2)
	{
		array[k] = rightArray[j];
		j++;
		k++;
	}

	free(leftArray);
	free(rightArray);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	int middle = size / 2;

	merge_sort(array, middle);
	merge_sort(array + middle, size - middle);

	merge(array, 0, middle - 1, size - 1);
}

