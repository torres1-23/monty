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
	else
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
		}
}
