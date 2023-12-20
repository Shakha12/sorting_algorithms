#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Gets the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int maxim, j;

	for (maxim = array[0], j = 1; j < size; j++)
	{
		if (array[j] > maxim)
			maxim = array[j];
	}

	return (maxim);
}

/**
 * radix_counting_sort - Sorts the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t y;

	for (y = 0; y < size; y++)
		count[(array[y] / sig) % 10] += 1;

	for (y = 0; y < 10; y++)
		count[y] += count[y - 1];

	for (y = size - 1; (int)y >= 0; y--)
	{
		buff[count[(array[y] / sig) % 10] - 1] = array[y];
		count[(array[y] / sig) % 10] -= 1;
	}

	for (y = 0; y < size; y++)
		array[y] = buff[y];
}

/**
 * radix_sort - Sorts an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int maxim, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	maxim = get_max(array, size);
	for (sig = 1; maxim / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
