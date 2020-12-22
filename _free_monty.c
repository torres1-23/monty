#include "monty.h"

/**
 * free_stuff - free allocated memory
 * @buffer: buffer to free.
 * @head: pointr head to free.
 */

void free_stuff(char *buffer, stack_t *head)
{
	stack_t *tmp = head, *new_head = head;

	if (head)
	{
		while (tmp)
		{
			new_head = tmp;
			tmp = tmp->next;
			free(new_head);
		}
	}
	free(buffer);
}
