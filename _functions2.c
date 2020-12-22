#include "monty.h"

/**
 * _pchar -  prints the char at the top of the stack
 * @head: pointer to head node of stack
 * @line_number: number of the line parsed.
 */

void _pchar(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (*head)
	{
		if (tmp->n < 0 || tmp->n > 127)
		{
			errors1(14, line_number);
			return;
		}
		printf("%c\n", tmp->n);
		return;
	}
	errors1(15, line_number);
}
