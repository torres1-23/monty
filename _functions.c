#include "monty.h"

/**
 * _push - push to stack
 * @head: pointer to head node of stack
 * @line_number: number of the line parsed.
 */

void _push(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head, *new;

	if (check_digit(arguments.value) == 0)
		errors(3, NULL, line_number);
	new = malloc(sizeof(stack_t));
	if (!new)
		errors(4, NULL, 0);
	if (!*head)
		new->next = NULL;
	else
	{
		new->next = tmp;
		tmp->prev = new;
	}
	new->n = atoi(arguments.value);
	new->prev = NULL;
	*head = new;
}

/**
 * _print_all - print stack from top
 * @head: pointer to head node of stack
 * @line_number: number of the line parsed.
 */

void _print_all(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	(void) line_number;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * _pint - print first element of stack
 * @head: pointer to head node of stack
 * @line_number: number of the line parsed.
 */

void _pint(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (*head)
	{
		printf("%d\n", tmp->n);
		return;
	}
	errors(5, NULL, line_number);
}

/**
 * _pop - removes top element of stack
 * @head: pointer to head node of stack
 * @line_number: number of the line parsed.
 */

void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (*head)
	{
		*head = tmp->next;
		if (tmp->next)
			tmp->next->prev = NULL;
		free(tmp);
		return;
	}
	errors(6, NULL, line_number);
}
