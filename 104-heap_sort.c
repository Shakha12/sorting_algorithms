#include "sort.h"

/**
 * swap_root - A function that swap the root nodes.
 * @array: The heap to sort.
 * @root: The root of the heap.
 * @hr: The higher index.
 * @size: The size of the array.
 * Return: Nothing
 */
void swap_root(int *array, size_t root, size_t hr, size_t size)
{
	size_t lw = 0, md = 0, tmp = 0;
	int aux = 0;

	while ((lw = (2 * root + 1)) <= hr)
	{
		tmp = root;
		md = lw + 1;
		if (array[tmp] < array[lw])
			tmp = lw;
		if (md <= hr && array[tmp] < array[md])
			tmp = md;
		if (tmp == root)
			return;
		aux = array[root];
		array[root] = array[tmp];
		array[tmp] = aux;
		print_array(array, size);
		root = tmp;
	}
}

/**
 * heap_sort - A function that sorts an array using heap algorithm.
 * @array: An array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void heap_sort(int *array, size_t size)
{
	size_t hr = 0, gap = 0;
	int tmp = 0;

		if (array == NULL || size < 2)
			return;

		for (gap = (size - 2) / 2; 1; gap--)
		{
			swap_root(array, gap, size - 1, size);
			if (gap == 0)
				break;
		}

		hr = size - 1;
		while (hr > 0)
	{
		tmp = array[hr];
		array[hr] = array[0];
		array[0] = tmp;
		print_array(array, size);
		hr--;
		swap_root(array, 0, hr, size);
	}
}
