#include "shell.h"

/**
 * construct_and_execute - A function that constructs the full path to an
 * executable and attempts execution.
 * @directory: the directory to concatenate with the command
 * @args: pointer to the argument count
 * Return: 0 if successful
 * This program conforms to the betty documentation style
 **/

int construct_and_execute(char *directory, char *args[])
{
	char *execut;
	int exec;
	size_t directory_len, command_len;

	directory_len = _strlen(directory);
	command_len = _strlen(args[0]);

	execut = malloc(directory_len + 1 + command_len + 1);

	if (execut == NULL)
	{
		perror("Memory allocation error");
		return (-1);
	}

	_strcpy(execut, directory);
	execut[directory_len] = '/';
	_strcpy(execut + directory_len + 1, args[0]);

	exec = execve(execut, args, NULL);

	free(execut);

	if (exec != -1)
	{
		return (0);
	}
	return (-1);
}
