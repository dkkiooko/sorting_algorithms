#include "sort.h"
void quicksort(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);

/**
* quick_sort - sort array of integers using quicksort algorithm
* @array: array ot integers to be sorted
* @size: amount of elements in array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, (int)size - 1, size);
}

/**
* quicksort - recursively sort array of integers
* @array: array of integers to be sorted
* @low: index to begin partition
* @high: index to end partition
* @size: amount of elements in array
*/
void quicksort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		quicksort(array, low, p - 1, size);
		quicksort(array, p + 1, high, size);
	}
}


/**
* partition - lumuto partition scheme
* @array: array to be partition
* @low: lower index to start partition
* @high: upper index to end partition
* @size: number of elements in array
* Return: index at which to partition
*/
int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (array[i] != array[j])
				print_array(array, size);
			i++;
		}
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
	if (array[i] != array[high])
		print_array(array, size);
	return (i);
}
