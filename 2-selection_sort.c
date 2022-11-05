#include "sort.h"
/**
* selection_sort - sorts array with selection algorithm
* @array: array to be sorted
* @size: length of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	size_t min;

	if (!array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
