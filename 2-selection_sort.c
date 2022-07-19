#include "sort.h"

/**
 * selection_sort - sorts an array using selection sorting
 * algorithm
 * @array: an array of integers
 * @size: length of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp, jLowest;

	if (!array)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		jLowest = i;
		for (j = (i + 1); j < size; j++)
		{
			if (array[jLowest] > array[j])
				jLowest = j;
		}
		if (jLowest != i)
		{
			tmp = array[i];
			array[i] = array[jLowest];
			array[jLowest] = tmp;
			print_array(array, size);
		}
	}
}
