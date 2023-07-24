#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int max_value = 0, i = 0;
	int *count_array = NULL, *tmp_array = NULL;

	if (!array || size < 2)
		return;

	max_value = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	count_array = malloc((max_value + 1) * sizeof(int));
	tmp_array = malloc(size * sizeof(int));

	if (!count_array || !tmp_array)
	{
		free(count_array);
		free(tmp_array);
		return;
	}

	for (i = 0; i <= max_value; i++)
		count_array[i] = 0;

	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;

	for (i = 1; i <= max_value; i++)
		count_array[i] += count_array[i - 1];

	print_array(count_array, max_value + 1);

	for (i = (int)size - 1; i >= 0; i--)
	{
		tmp_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = tmp_array[i];

	free(count_array);
	free(tmp_array);
}
