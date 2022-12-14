#include "sort.h"
/**
* shell_sort - shell sort algorithm applied to C array
* @array: array of integers
* @size: length of array
*/
void shell_sort(int *array, size_t size)
{
	size_t interval = 1;
	size_t inner, outer;
	int valueToInsert;

	if (!array || size < 2)
		return;

	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (outer = interval; outer < size; outer++)
		{
			valueToInsert = array[outer];
			inner = outer;
			while (inner > interval - 1 && array[inner - interval] >= valueToInsert)
			{
				array[inner] = array[inner - interval];
				inner = inner - interval;
			}
			array[inner] = valueToInsert;
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
