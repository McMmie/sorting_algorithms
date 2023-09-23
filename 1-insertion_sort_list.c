#include "sort.h"
#include <stdlib.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: a doubly linked list to be sorted
 *
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *ptr;

	ptr = (*list)->next;
	if (ptr->next != NULL)
	{
		while (ptr->prev != NULL && ptr->prev->n > ptr->n)
		{
			temp = ptr->prev;
			if (temp->prev != NULL)
			{
				temp->prev->next = ptr;
			}
			if (ptr->next != NULL)
			{
				ptr->next->prev = temp;
			}

			ptr->prev = temp->prev;
			temp->next = ptr->next;
			temp->prev = ptr;
			ptr->next = temp;


			if (ptr->prev == NULL)
				*list = ptr;


			ptr->next->prev = temp;


			print_list(*list);
		}
		ptr = ptr->next;
	}

}
