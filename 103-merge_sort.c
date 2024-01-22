#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - A function that sorts an array
 * @array: The array to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t idx = 0;
	int *temp_array = NULL;

	if (array == NULL || size < 2)
		return;
	temp_array = malloc(sizeof(int) * size);
	if (temp_array == NULL)
		return;
	for (; idx < size; idx++)
		temp_array[idx] = array[idx];
	new_merge_partition(0, size, array, temp_array);
	free(temp_array);
}

/**
 * new_merge - A function that sorts the sub-arrays.
 * @low: Lower index.
 * @mid: Middle index.
 * @top: Top index.
 * @dest: Destination for data.
 * @src: Input data.
 */
void new_merge(size_t low, size_t mid, size_t top, int *dest, int *src)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + low, mid - low);
	printf("[right]: ");
	print_array(src + mid, top - mid);
	i = low;
	j = mid;
	k = low;
	for (; k < top; k++)
	{
		if (i < mid && (j >= top || src[i] <= src[j]))
		{
			dest[k] = src[i];
			i++;
		}
		else
		{
			dest[k] = src[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + low, top - low);
}

/**
 * new_merge_partition - recursively split an array
 * @low: Lower index.
 * @top: Top index.
 * @array: The array to sort.
 * @temp: The copy of the array.
 */
void new_merge_partition(size_t low, size_t top, int *array, int *temp)
{
	size_t mid = 0;

	if (top - low < 2)
		return;
	mid = (low + top) / 2;
	new_merge_partition(low, mid, array, temp);
	new_merge_partition(mid, top, array, temp);
	new_merge(low, mid, top, array, temp);
	for (mid = low; mid < top; mid++)
		temp[mid] = array[mid];
}
