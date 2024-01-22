#include "sort.h"

/**
 * radix_sort - Radix Sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int exp, max = 0, *output = NULL;

	if (!array || size < 2)
		return;

	max = get_max_value(array, size);
	output = malloc(size * sizeof(int));
	if (!output)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp, output);
		print_array(array, size);
	}

	free(output);
}

/**
 * get_max_value - Maximum value in an array.
 * @arr: The array.
 * @n: Size of the array.
 * Return: Maximum value in the array.
 */
int get_max_value(int *arr, int n)
{
	int i, max = arr[0];

	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

/**
 * count_sort - Counting sort based on a digit.
 * @arr: Array to be sorted.
 * @n: Size of the array.
 * @exp: Exponent for the current digit.
 * @output: Array for temporary values.
 */
void count_sort(int *arr, size_t n, int exp, int *output)
{
	int i, count[10] = {0};

	for (i = 0; i < (int)n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)n; i++)
		arr[i] = output[i];
}
