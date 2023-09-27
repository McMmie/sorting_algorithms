#include "sort.h"
#include <stdio.h>


size_t partition(int *arr, size_t low, size_t high);

void quicksort(int *array, size_t low, size_t high);

void swap(int *a, int *b);

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
	size_t low, high;

	low = 0;
	high = size - 1;

	quicksort(array, low, high);
}

/**
 * quicksort - quick sort in recursive mode
 * @array: array to sort
 * @low: the first index
 * @high: the last index
 *
 * Return: Nothing
 */

void quicksort(int *array, size_t low, size_t high)
{
	int temp[100];

	size_t part;
	int i = -1;

	temp[++i] = low;
	temp[++i] = high;
	while (i >= 0)
	{
		high = temp[i--];
		low = temp[i--];
		part = partition(array, low, high);
		if (part - 1 > low)
		{
			temp[++i] = low;
			temp[++i] = part - 1;
		}

		if (part + 1 < high)
		{
			temp[++i] = part + 1;
			temp[++i] = high;
		}
		printf("partition: %ld\n", part);
	}
}

/**
 * swap - swaps values of an array
 * @a: first value
 * @b: second value
 *
 * Return: nothing
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - uses the lomuto partition scheme to partition an array
 * @arr: array to partition
 * @low: first index
 * @high: last index
 *
 * Return: new partition
 */

size_t partition(int *arr, size_t low, size_t high)
{
	size_t j, i = (low - 1);

	int tmp, pivot = arr[high];

	printf("pivot: %d\n", pivot);
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
			}
		}
	}
	if (i != high)
	{
		tmp = arr[i + 1];
		arr[i + 1] = arr[high];
		arr[high] = tmp;
	}

	print_array(arr, high + 1);
	return (i + 1);
}
