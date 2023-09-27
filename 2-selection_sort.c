#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to be sorted
 * @size: the size of the array
 *
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t idx, i, j = 1;
	int temp;

	if (size < 2)
		return;


	for (i = 0; i < size - 1; i++)
	{
		idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[idx])
			{
				idx = j;
			}
		}
		if (idx != i)
		{
			temp = array[i];
			array[i] = array[idx];
			array[idx] = temp;
			print_array(array, size);
		}
	}
}
