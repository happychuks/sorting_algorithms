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
