#include "sort.h"

/**
 * ints_swapper - Swaps two integers in an array
 * @first_int: The first integer to swap
 * @second_int: The second integer to swap
 */
void ints_swapper(int *first_int, int *second_int)
{
	int temp;

	temp = *first_int;
	*first_int = *second_int;
	*second_int = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: Array of integers to be sorted
 * @size: Size of array to be sorted
 *
 * Description: Prints the array after each swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubble_bool = false;

	if (array == NULL || size < 2)
		return;

	while (bubble_bool == false)
	{
		bubble_bool = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				ints_swapper(array + i, array + i + 1);
				print_array(array, size);
				bubble_bool = false;
			}
		}
		len--;
	}
}
