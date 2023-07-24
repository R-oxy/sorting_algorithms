#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Pointer to the head of the list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	bool swapped = false;
	listint_t *current = NULL, *aux = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = *list;
	while (current->next)
	{
		if (current->n > current->next->n)
		{
			current->next->prev = current->prev;
			if (current->next->prev)
				current->prev->next = current->next;
			else
				*list = current->next;

			current->prev = current->next;
			current->next = current->next->next;
			current->prev->next = current;
			if (current->next)
				current->next->prev = current;

			current = current->prev;
			print_list(*list);

			if (current->prev && current->prev->n > current->n)
			{
				if (!swapped)
					aux = current->next;
				swapped = true;
				current = current->prev;
				continue;
			}
		}
		if (!swapped)
			current = current->next;
		else
			current = aux, swapped = false;
	}
}
