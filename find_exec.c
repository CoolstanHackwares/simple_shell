#include "shell.h"

/**
 * find_exec - A program that finds the executable part of the entered command.
 * @command_cache: The command input.
 * Return: A pointer to the executable part of the command.
 * This program conforms to the betty documentation style
 **/

char *find_exec(char *command_cache)
{
	char *delim = " ";

	return (_strtok(command_cache, delim));
}

/**
 * _strdup - A function that duplicates a string.
 *
 * @str: The input string to duplicate.
 *
 * Return: If str is NULL or memory allocation fails, returns NULL;
 * otherwise, returns a pointer to the duplicated string.
 * This program conforms to the betty documentation style
 **/

char *_strdup(const char *str)
{
	char *duplicate;
	unsigned int length = 0, i;

	/* Check if the input string is NULL */
	if (str == NULL)
		return (NULL);

	/* Calculate the length of the input string */
	while (str[length] != '\0')
		length++;

	/* Allocate memory for the duplicated string */
	duplicate = malloc((length + 1) * sizeof(char));

	/* Check if memory allocation fails */
	if (duplicate == NULL)
		return (NULL);

	/* Copy the content of the input string to the duplicated string */
	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];

	return (duplicate);
}

/**
 * print_environment - A function that prints the current environment
 * This program conforms to the betty documentation style
 **/
void print_environment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		size_t len = _strlen(*env);

		/* Use write to print the environment string to STDOUT */
		write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);

		env++;
	}
}

