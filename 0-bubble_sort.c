#include "sort.h"

/**
 * swap_two - Swap two integers .
 * @a: The first integer.
 * @b: The second integer .
 */
void swap_two(int *x, int *y)
{
	int tempo;

	tempo = *x;
	*x = *y;
	*y = tempo;
}

/**
 * bubble_sort - This func Sorts an array of integers in ascending order.
 * @array:Array to be sorted.
 * @size: Size of the array.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, lenght = size;
	bool swapped = false;

	if (array == NULL || size < 2)
		return;

	while (swapped == false)
	{
		swapped = true;
		for (x = 0; x < lenght - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				swap_two(array + x, array + x + 1);
				print_array(array, size);
				swapped = false;
			}
		}
		lenght--;
	}
}
