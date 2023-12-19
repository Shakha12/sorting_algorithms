#include "sort.h"

/**
  * bubble_sort - Bubble sorting function.
  * @array: The array to sort.
  * @size: THe aaray length.
  * Return: Nothing.
  */
void bubble_sort(int *array, size_t size)
{
	size_t k = 0, l = 0;
	int aux = 0;

	if (array == NULL || size == 0)
		return;
	for (; k < size - 1; k++)
	{
		for (l = 0; l < size - k - 1; l++)
		{
			if (array[l] > array[l + 1])
			{
				aux = array[l + 1];
				array[l + 1] = array[l];
				array[l] = aux;
				print_array(array, size);
			}
		}
	}
}
