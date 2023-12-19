#include "sort.h"

/**
 * quick_sort - function that uses the Quick sort algorithm
 *              to sort an array of integers in ascending order.
 * @array: array
 * @size: array's size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_s(array, 0, size - 1, size);
}

/**
 * partition - partition
 * @array: array
 * @lw: lower
 * @hr: higher
 * @size: array's size
 * Return: k
 */
int partition(int *array, int lw, int hr, size_t size)
{
	int k = lw - 1, l = lw;
	int pivot = array[hr], aux = 0;

	for (; l < hr; l++)
	{
		if (array[l] < pivot)
		{
			k++;
			if (array[k] != array[l])
			{
				aux = array[k];
				array[k] = array[l];
				array[l] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[k + 1] != array[hr])
	{
		aux = array[k + 1];
		array[k + 1] = array[hr];
		array[hr] = aux;
		print_array(array, size);
	}
	return (k + 1);
}

/**
 * quick_s - quick sort
 * @array: given array
 * @lw: lower
 * @hr:higher
 * @size: array's size
 * Return: void
 */
void quick_s(int *array, int lw, int hr, size_t size)
{
	int pivot;

	if (lw < hr)
	{
		pivot = partition(array, lw, hr, size);
		quick_s(array, lw, pivot - 1, size);
		quick_s(array, pivot + 1, hr, size);
	}
}
