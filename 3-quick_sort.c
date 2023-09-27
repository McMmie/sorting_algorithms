#include "sort.h"
#include <stdlib.h>


size_t partition(int *arr, size_t low, size_t high, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	size_t low, high, part;
	int *temp;
	int i = -1;

	low = 0;
	high = size - 1;

	temp = malloc(sizeof(int) * (high - low + 1));

	temp[++i] = low;
	temp[++i] = high;
	while (i >= 0)
	{
		high = temp[i--];
		low = temp[i--];
		part = partition(array, low, high, size);
		if (part > low)
		{
			temp[++i] = low;
			temp[++i] = part - 1;
		}

		if (part < high)
		{
			temp[++i] = part + 1;
			temp[++i] = high;
		}
	}

	free(temp);
}

/**
 * partition - uses the lomuto partition scheme to partition an array
 * @arr: array to partition
 * @low: first index
 * @high: last index
 * @size: size of the array
 *
 * Return: new partition
 */

size_t partition(int *arr, size_t low, size_t high, size_t size)
{
	size_t j, i = (low - 1);

	int tmp, pivot = arr[high];

	for (j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				print_array(arr, size);
			}
		}
	}
	if (i != high)
	{
		tmp = arr[i + 1];
		arr[i + 1] = arr[high];
		arr[high] = tmp;
	}

	print_array(arr, size);
	return (i + 1);
}
