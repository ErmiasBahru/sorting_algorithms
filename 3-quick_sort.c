#include "sort.h"

/**
 * partition_array - partitions an array
 * @array: array of integers
 * @low: the lowest position of array
 * @high: highest position of the array to be partitioned
 * @size: length of the main array
 * Return: new pivot index
 */
int partition_array(int *array, int low, int high, size_t size)
{
	int i = (low - 1);
	int pivot = array[high];
	int j, tmp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			if (i != j)
				print_array(array, size);
		}
	}

	if (array[i + 1] != array[high])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		if ((i + 1) != j)
			print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort - sorts an array recursively using quicksort
 * @array: array of integers
 * @low: the lowest position of array
 * @high: highest position of the array to be partitioned
 * @size: length of the main array
 * Returns: nothing
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot = 0;

	if (low < high)
	{
		pivot = partition_array(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, (pivot + 1), high, size);
	}
}

/**
 * quick_sort - base of the quicksort algorithm that
 * initializes it's implementaion
 * @array: array of integers
 * @size: length of the main array
 */
void quick_sort(int *array, size_t size)
{
	if (array || size > 1)
		quicksort(array, 0, (size - 1), size);
}
