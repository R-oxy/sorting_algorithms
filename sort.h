#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define INCREMENT 1
#define DECREMENT -1

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quicksort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void swap(int *array, int i, int j);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_list_nodes(listint_t **list, listint_t *node);
listint_t *get_last_dlistint(listint_t *head);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size);
void heap_sort(int *array, size_t size);
void sift_down(int *array, size_t start, size_t end, size_t size);
void radix_sort(int *array, size_t size);
int get_max(int *array, size_t size);
void counting_sort_radix(int *array, size_t size, int exp);
void bitonic_sort(int *array, size_t size);
void bitonic_compare(int *array, size_t size, int dir, size_t i, size_t j);
void bitonic_merge(int *array, size_t size, int dir, size_t low, size_t count);
void bitonic_sort_recursive(int *array, size_t size, int dir, size_t low, size_t count);
void quick_sort_hoare(int *array, size_t size);
size_t hoare_partition(int *array, ssize_t low, ssize_t high);
void quick_sort_recursive(int *array, ssize_t low, ssize_t high);

#endif /* SORT_H */
