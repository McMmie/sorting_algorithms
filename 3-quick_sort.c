#include "sort.h"
#include <stdlib.h>

void quicksort(int *arr, int low, int high, int size);

int partition(int *arr, int low, int high, int size);

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
	int low, high;


	low = 0;
	high = size - 1;
	if ((size < 2) || (array == NULL))
		return;

	quicksort(array, low, high, size);
}

/**
 * quicksort - sorts an array of integers recursively
 * @arr: array to be sorted
 * @low: first index
 * @high: last index
 * @size: size of the array
 *
 * Return: Nothing
 */
void quicksort(int *arr, int low, int high, int size)
{
	int part;

	if (low < high)
	{
		part = partition(arr, low, high, size);
		quicksort(arr, low, part - 1, size);
		quicksort(arr, part + 1, high, size);
	}
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

int partition(int *arr, int low, int high, int size)
{
	int j, i = (low - 1);

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

	tmp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = tmp;

	print_array(arr, size);
	return (i + 1);
}
