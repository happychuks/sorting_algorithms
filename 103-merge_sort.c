#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* merge_arrays - Merges two sorted arrays into one!
* @start: The starting index of the first array!
* @middle: Ending and starting index of first and second arrays
* @end: The ending index of the second array!
* @destination: The array where the merged result will be stored!
* @source: The original array containing two sorted halves to be merged!
*/
void merge_arrays(
size_t start, size_t middle, size_t end, int *destination, int *source)
{
	size_t i = start, j = middle, k = start;

	printf("Merging...\n");
	printf("[Left]: ");
	print_array(source + start, middle - start);
	printf("[Right]: ");
	print_array(source + middle, end - middle);

	while (k < end)
	{
		if (i < middle && (j >= end || source[i] <= source[j]))
		{
			destination[k] = source[i];
			i++;
		}
		else
		{
			destination[k] = source[j];
			j++;
		}
		k++;
	}

	printf("[Done]: ");
	print_array(destination + start, end - start);
}

/**
* recursive_merge - Recursively splits and merges the array
* @low: The starting index of the sub-array
* @high: The ending index of the sub-array
* @array: The original array to be sorted
* @temp_storage: Temporary storage for merging
*/
void recursive_merge(size_t low, size_t high, int *array, int *temp_storage)
{
	size_t middle = 0;

	if (high - low < 2)
		return;

	middle = (low + high) / 2;

	recursive_merge(low, middle, array, temp_storage);
	recursive_merge(middle, high, array, temp_storage);
	merge_arrays(low, middle, high, array, temp_storage);

	for (middle = low; middle < high; middle++)
		temp_storage[middle] = array[middle];
}

/**
* merge_sort - Sorts an array of integers
* @array: The array to be sorted!
* @size: The size of the array!
*/
void merge_sort(int *array, size_t size)
{
	size_t i = 0;
	int *temp_storage = NULL;

	if (array == NULL || size < 2)
		return;

	temp_storage = malloc(sizeof(int) * size);
	if (temp_storage == NULL)
		return;

	for (; i < size; i++)
		temp_storage[i] = array[i];

	recursive_merge(0, size, array, temp_storage);
	free(temp_storage);
}
