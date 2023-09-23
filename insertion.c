#include "sort.h"
#include <stdlib.h>

/**
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *ptr, *nxt;

	ptr = (*list)->next;

	while (ptr != NULL)
	{
		tmp = ptr->prev;
		nxt = ptr->next;
		if (tmp != NULL && tmp->n > ptr->n)
		{

			if (tmp->prev != NULL)
			{
				tmp->prev->next = ptr;
			}

			if (ptr->next != NULL)
			{
				ptr->next->prev = tmp;
			}

			tmp->next = nxt;
			tmp->prev = ptr;
			ptr->next = tmp;
			ptr->next->prev = tmp;

			if (ptr->prev == NULL)
			{
				*list = ptr;
			}
			

			print_list(*list);
		}
		ptr = nxt;

	}

}