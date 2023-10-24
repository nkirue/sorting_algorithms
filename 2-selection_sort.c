#include "sort.h"

/**
 * swap_two - This swaps two integers.
 * @x: The first integer.
 * @y: The second integer.
 */
void swap_two(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * selection_sort - This sorts an array of integers
 * @array: An array of int.
 * @size: The size.
 *
 */
void selection_sort(int *array, size_t size)
{
	int *mn;
	size_t x, y;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		mn = array + x;
		for (y = x + 1; y < size; y++)
			mn = (array[y] < *mn) ? (array + y) : mn;

		if ((array + x) != mn)
		{
			swap_two(array + x, mn);
			print_array(array, size);
		}
	}
}
