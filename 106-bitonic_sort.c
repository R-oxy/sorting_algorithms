#include "sort.h"


/**
 * swap - Swap two elements in an array
 * @array: The array
 * @i: Index of the first element
 * @j: Index of the second element
 *
 * Return: Nothing
 */
void swap(int *array, int i, int j)
{
	int temp;

	if (array[i] != array[j])
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, j + 1);
	}
}

/**
 * bitonic_compare - Compare two elements and swap them if needed
 * @array: The array to be sorted
 * @size: The size of the array
 * @dir: The direction of sorting (1 for ascending, 0 for descending)
 * @i: The index of the first element to be compared
 * @j: The index of the second element to be compared
 *
 * Return: Nothing
 */
void bitonic_compare(int *array, size_t size, int dir, size_t i, size_t j)
{
	int temp;

	if ((array[i] > array[j] && dir == 1) || (array[i] < array[j] && dir == 0))
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;

		print_array(array, size);
	}
}

/**
 * bitonic_merge - Merge two subarrays in a bitonic manner
 * @array: The array to be sorted
 * @size: The size of the array
 * @dir: The direction of sorting (1 for ascending, 0 for descending)
 * @low: The starting index of the first subarray
 * @count: The number of elements to be merged
 *
 * Return: Nothing
 */
void bitonic_merge(int *array, size_t size, int dir, size_t low, size_t count)
{
	size_t k;
	size_t i;

	if (count > 1)
	{
		k = count / 2;

		for (i = low; i < low + k; i++)
			bitonic_compare(array, size, dir, i, i + k);

		bitonic_merge(array, size, dir, low, k);
		bitonic_merge(array, size, dir, low + k, k);
	}
}

/**
 * bitonic_sort_recursive - Recursively sort a bitonic sequence
 * @array: The array to be sorted
 * @size: The size of the array
 * @dir: The direction of sorting (1 for ascending, 0 for descending)
 * @low: The starting index of the subarray to be sorted
 * @count: The number of elements to be sorted
 *
 * Return: Nothing
 */
void bitonic_sort_recursive(int *array, size_t size, int dir, size_t low, size_t count)
{
	size_t k;

	if (count > 1)
	{
		k = count / 2;

		printf("Merging [%lu/%lu] (%s):\n", count, count, (dir == 1) ? "UP" : "DOWN");
		print_array(array + low, count);

		bitonic_sort_recursive(array, size, 1, low, k);
		bitonic_sort_recursive(array, size, 0, low + k, k);

		bitonic_merge(array, size, dir, low, count);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * using the Bitonic sort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_sort_recursive(array, size, 1, 0, size);
}
