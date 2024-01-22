#include "sort.h"

/**
* quick_sort_hoare - Initiate QuickSort using Hoare's scheme
* @array: Array to be sorted
* @size: Number of elements
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
* swap_elements - Swap two elements in an array
* @array: The array
* @item1: Index of first element
* @item2: Index of second element
*/
void swap_elements(int *array, ssize_t item1, ssize_t item2)
{
	int tmp = array[item1];

	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
* hoare_partitioner - Implement Hoare's partition scheme for QuickSort
* @array: The array to be partitioned
* @first: Index of first element
* @last: Index of last element
* @size: Number of elements
* Return: Position of last sorted element
*/
int hoare_partitioner(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;

	int pivot = array[last];

	while (1)
	{
		do {
		  current++;
		  } while (array[current] < pivot);
		do {
		  finder--;
		  } while (array[finder] > pivot);

		if (current >= finder)
		  return (current);

		swap_elements(array, current, finder);
		print_array(array, size);
	}
}

/**
* quick_sort_recursive - Implement recursive step of QuickSort.
* @array: Array to be sorted.
* @first: Index of first element.
* @last: Index of last element.
* @size: Number of elements.
*/
void quick_sort_recursive(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partitioner(array, first, last, size);
		quick_sort_recursive(array, first, position - 1, size);
		quick_sort_recursive(array, position, last, size);
	}
}
