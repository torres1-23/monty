#include "monty.h"

/**
 * main - Entry point, file parsing.
 * @argc: number of arguments.
 * @argv: array of arguments.
 * Return: 0 on success.
 */

int main(int argc, char **argv)
{
	char *buffer = NULL;
	size_t buffersize = 0;
	FILE *stream;
	stack_t *head = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
		errors(0, NULL, 0);
	stream = fopen(argv[1], "r");
	if (!stream)
		errors(1, argv[1], 0);
	while (getline(&buffer, &buffersize, stream) != -1)
	{
		line_number++;
		if (*buffer == '\n' && *buffer == '#')
			continue;
		arguments.command = strtok(buffer, "\n ");
		if (!arguments.command ||
			strcmp(arguments.command, "nop") == 0 || *arguments.command == '#')
			continue;
		arguments.value = strtok(NULL, "\n ");
		get_opcode(&head, line_number);
	}
	free_stuff(buffer, head);
	fclose(stream);
	return (0);
}
