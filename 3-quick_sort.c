#include "sort.h"

void swap_two(int *x, int *y);
int lomutopartition(int *array, size_t size, int lef, int rig);
void lomutosort(int *array, size_t size, int lef, int righ);
void quick_sort(int *array, size_t size);

/**
 * swap_two - func swaps two integers.
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
 * lomutopartition - Order a subset of an array of integers
 *
 * @array: The array.
 * @size: The size.
 * @lef: starting index of the subset.
 * @righ: ending index of the subset.
 *
 * Return: partition index.
 */
int lomutopartition(int *array, size_t size, int lef, int righ)
{
	int *piv, abo, be;

	piv = array + righ;
	for (abo = be = lef; be < righ; be++)
	{
		if (array[be] < *piv)
		{
			if (abo < be)
			{
				swap_two(array + be, array + abo);
				print_array(array, size);
			}
			abo++;
		}
	}

	if (array[abo] > *piv)
	{
		swap_two(array + abo, piv);
		print_array(array, size);
	}

	return (abo);
}

/**
 * lomutosort - This executes the quicksort algorithm through recursion.
 * @array: An array of integers.
 * @size: The size.
 * @lef: starting index.
 * @righ: ending index .
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomutosort(int *array, size_t size, int lef, int righ)
{
	int par;

	if (righ - lef > 0)
	{
		par = lomutopartition(array, size, lef, righ);
		lomutosort(array, size, lef, par - 1);
		lomutosort(array, size, par + 1, righ);
	}
}

/**
 * quick_sort - Sort an array of integers
 *
 * @array: An array .
 * @size: The size.
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomutosort(array, size, 0, size - 1);
}
