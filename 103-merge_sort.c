#include "sort.h"

/**
 * merge - Merges two subarrays into a single sorted array.
 * @array: The original array.
 * @left: The left subarray.
 * @left_size: The size of the left subarray.
 * @right: The right subarray.
 * @right_size: The size of the right subarray.
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *tmp_array = malloc(sizeof(int) * (left_size + right_size));

	if (!tmp_array)
		return;

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			tmp_array[k++] = left[i++];
		else
			tmp_array[k++] = right[j++];
	}

	while (i < left_size)
		tmp_array[k++] = left[i++];

	while (j < right_size)
		tmp_array[k++] = right[j++];

	for (i = 0; i < left_size + right_size; i++)
		array[i] = tmp_array[i];

	free(tmp_array);

	printf("[Done]: ");
	print_array(array, left_size + right_size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t mid = size / 2;
		int *left = array;
		int *right = array + mid;

		merge_sort(left, mid);
		merge_sort(right, size - mid);
		merge(array, left, mid, right, size - mid);
	}
}
