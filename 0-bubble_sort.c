#include "sort.h"

/**
* bubble_sort - bubble sort algorithm
* @array: array of integers
* @size: length of array
* Return: nothing
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp = 0;

	if (!array)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}

}
