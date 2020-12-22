#include "monty.h"

/**
 * errors - print to stderr error message
 * @code: code of error.
 * @argv: args to print.
 * @n_line: line number.
 */

void errors(unsigned int code, char *argv, unsigned int n_line)
{
	if (code == 0)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else if (code == 1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	else if (code == 2)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", n_line, arguments.command);
		exit(EXIT_FAILURE);
	}
	else if (code == 3)
	{
		fprintf(stderr, "L%d: usage: push integer\n", n_line);
		exit(EXIT_FAILURE);
	}
	else if (code == 4)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	else if (code == 5)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", n_line);
		exit(EXIT_FAILURE);
	}
	else if (code == 6)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", n_line);
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}
}

/**
 * errors1 - print to stderr error message
 * @code: code of error.
 * @n_line: line number.
 */

void errors1(unsigned int code, unsigned int n_line)
{
	if (code == 8)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}
	else if (code == 9)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}
	else if (code == 10)
	{
		fprintf(stderr, "L%d: division by zero\n", n_line);
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}
}
