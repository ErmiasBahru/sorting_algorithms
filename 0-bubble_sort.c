#include "sort.h"

/**
 * bubble_sort - sorts an array of integers with Bubble Sort
 * @array: param
 * @size: param
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, n, n1;
    int swap;

    if (array == NULL || size < 2)
        return;

    n = size;
    while (n > 0)
    {
        n1 = 0;
        for (i = 0; i < n - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap = array[i];
                array[i] = array[i + 1];
                array[i + 1] = swap;
                n1 = i + 1;
                print_array(array, size);
            }
        }
        n = n1;
    }
}
