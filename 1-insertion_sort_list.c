#include "sort.h"

/**
* insertion_sort_list - sorts doubly linked list of integers in ascending
*
* @list: doubly linked list
* Return: nothing at all
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *lead, *follow, *new, *temp;

	if (!list || !(*list) || !((*list)->next))
		return;

	follow = (*list);
	lead = (*list)->next;
	while (lead)
	{
		new = lead->next;
		while (follow && lead->n < follow->n)
		{
			if (follow->prev)
				follow->prev->next = lead;
			else
				*list = lead;
			if (lead->next)
				lead->next->prev = follow;
			temp = lead->next;
			lead->next = follow;
			lead->prev = follow->prev;
			follow->next = temp;
			follow->prev = lead;
			print_list(*list);
			follow = lead->prev;
		}
		lead = new;
		if (lead)
			follow = lead->prev;
	}
}
