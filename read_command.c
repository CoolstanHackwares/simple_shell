#include "shell.h"

/**
 * read_command - A function that reads the given command
 * @command_cache: the memory cache
 * @command_bytes: the memory size
 * Return: pointer
 **/

ssize_t read_command(char **command_cache, size_t *command_bytes)
{
	ssize_t command;

	command = getline(command_cache, command_bytes, stdin);

	if (command == -1)
	{
		if (feof(stdin))
		{
			cleanup(*command_cache);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Read command failed");
			cleanup(*command_cache);
			exit(EXIT_FAILURE);
		}
	}

	return (command);
}
