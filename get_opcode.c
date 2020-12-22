#include "monty.h"

/**
 * get_opcode - get opcodes and arguments for stack
 * @head: pointer to head node of stack
 * @line_number: number of the line parsed.
 */

void get_opcode(stack_t **head, unsigned int line_number)
{
	int i = 0;
	instruction_t op_codes[] = {
		{"push", _push},
		{"pall", _print_all},
		{"pint", _pint},
		{NULL, NULL}
	};
	for (i = 0; op_codes[i].opcode; i++)
	{
		if (strcmp(arguments.command, op_codes[i].opcode) == 0)
		{
			op_codes[i].f(head, line_number);
			return;
		}
	}
	errors(2, arguments.command, line_number);
}

/**
 * check_digit - Function that checks if is digit or not
 * @string: string to verify
 * Return: 1 if is digit 0 if not.
 */

int check_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}
