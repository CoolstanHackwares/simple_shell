#include "shell.h"

/**
 * prepare_command_args - A program that parses a command string and stores
 * arguments in an array
 * @command_cache: The command to be parsed
 * @args: An array to store the arguments.
 * Return: 0 if successful, -1 if an error occurs.
 * This program conforms to the betty documentation style
 **/

int prepare_command_args(char *command_cache, char **args)
{
	char *delim = " ";
	char *token;
	int arg_index = 0;

	token = _strtok(command_cache, delim);
	while (token != NULL)
	{
		args[arg_index++] = token;
		token = _strtok(NULL, delim);

		if (arg_index >= MAX_ARGUMENTS - 1)
		{
			perror("Too many command arguments.\n");
			return (-1);
		}
	}
	args[arg_index] = NULL;

	return (0);
}
