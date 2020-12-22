#include "monty.h"

/**
 * main - Entry point, file parsing.
 * @argc: number of arguments.
 * @argv: array of arguments.
 * Return: 0 on success.
 */

int main(int argc, char **argv)
{
	size_t buffersize = 0;
	FILE *stream;
	stack_t *head = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
		errors(0, NULL, 0);
	stream = fopen(argv[1], "r");
	if (!stream)
		errors(1, argv[1], 0);
	while (getline(&arguments.buffer, &buffersize, stream) != -1)
	{
		line_number++;
		if (*arguments.buffer == '\n')
			continue;
		arguments.command = strtok(arguments.buffer, "\n ");
		if (!arguments.command || *arguments.command == '#')
			continue;
		arguments.value = strtok(NULL, "\n ");
		get_opcode(&head, line_number);
	}
	free_stuff(head);
	fclose(stream);
	return (0);
}
