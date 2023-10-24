#include "sort.h"

/**
 * swap_twonodes - This swaps two nodes in a listint_t.
 * @h_1: A pointer to the head .
 * @n_1: A pointer to the first node.
 * @n_2: The second node.
 */
void swap_twonodes(listint_t **h_1, listint_t **n_1, listint_t *n_2)
{
	(*n_1)->next = n_2->next;
	if (n_2->next != NULL)
		n_2->next->prev = *n_1;
	n_2->prev = (*n_1)->prev;
	n_2->next = *n_1;
	if ((*n_1)->prev != NULL)
		(*n_1)->prev->next = n_2;
	else
		*h_1 = n_2;
	(*n_1)->prev = n_2;
	*n_1 = n_2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: A pointer to the head.
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ite, *insrt, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (ite = (*list)->next; ite != NULL; ite = temp)
	{
		temp = ite->next;
		insrt = ite->prev;
		while (insrt != NULL && ite->n < insrt->n)
		{
			swap_twonodes(list, &insrt, ite);
			print_list((const listint_t *)*list);
		}
	}
}
