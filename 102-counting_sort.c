#include "sort.h"

/**
* counting_sort - sorts array of integers in ascending order
* using counting sort algorithm
* @array: array of integers
* @size: length of array
*/
void counting_sort(int *array, size_t size)
{
	int max = array[0];
	size_t j;
	int p = (int)(size - 1);
	int i;
	int k;
	int *count;
	int *output;

	output = (int *)malloc(sizeof(int) * size);
	if (!output)
		return;

	if (!array || size < 2)
		return;
	for (j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}
	count = (int *)malloc(sizeof(int) * max + 1);
	if (!count)
		return;
	for (j = 0; j < size; j++)
		count[array[j]]++;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (k = p; k >= 0; k--)
	{
		output[count[array[k]] - 1] = array[k];
		count[array[k]]--;
	}
	for (j = 0; j < size; j++)
	{
		array[j] = output[j];
	}
}
