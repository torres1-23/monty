#include "monty.h"

/**
 * _add - add the two top most numbers of the stack
 * @head: pointer to head node of stack
 * @line_number: number of the line parsed.
 */

void _add(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (list_len(*head) < 2)
	{
		errors1(8, line_number);
		return;
	}
	tmp->next->n = tmp->n + tmp->next->n;
	_pop(head, line_number);
}

/**
 * _sub - substracts the two top most numbers of the stack
 * @head: pointer to head node of stack
 * @line_number: number of the line parsed.
 */

void _sub(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (list_len(*head) < 2)
	{
		errors1(9, line_number);
		return;
	}
	tmp->next->n = tmp->next->n - tmp->n;
	_pop(head, line_number);
}

/**
 * _div - divides the two top most numbers of the stack
 * @head: pointer to head node of stack
 * @line_number: number of the line parsed.
 */

void _div(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (list_len(*head) == 0)
	{
		errors1(10, line_number);
		return;
	}
	if (list_len(*head) < 2)
	{
		errors1(11, line_number);
		return;
	}
	tmp->next->n = tmp->next->n / tmp->n;
	_pop(head, line_number);
}
