#include "shell.h"

#define READ_SIZE 1024

/**
 * read_input - Reads input from standard input into a buffer.
 * @ptr: Pointer to the buffer where the input is stored.
 * @num: Pointer to the size of the buffer.
 *
 * Return: The number of bytes read, or -1 on failure.
 **/

ssize_t read_input(char **ptr, size_t *num)
{
	static char buffer[READ_SIZE];
	static ssize_t bytes_read;
	ssize_t i;

	if (*num == 0 || *ptr == NULL)
		return (-1);

	bytes_read = read(STDIN_FILENO, buffer, READ_SIZE);

	if (bytes_read == -1)
	{
		perror("Read input failed");
		return (-1);
	}
	else if (bytes_read == 0)
	{
		return (0);
	}

	*ptr = malloc(bytes_read + 1);
	if (*ptr == NULL)
	{
		perror("Memory allocation error");
		return (-1);
	}

	(*ptr)[bytes_read] = '\0';

	for (i = 0; i < bytes_read; ++i)
	{
		(*ptr)[i] = buffer[i];
	}

	return (bytes_read);
}

/**
 * _getline - Custom getline function.
 * @ptr: Pointer to the buffer where the line is stored.
 * @num: Pointer to the size of the buffer.
 *
 * Return: The number of bytes read (including newline), or -1 on failure.
 **/
ssize_t _getline(char **ptr, size_t *num)
{
	static char buffer[READ_SIZE];
	static ssize_t bytes_read;
	size_t i;
	char *newline_position;
	ssize_t input_bytes;

	input_bytes = read_input(ptr, num);
	if (input_bytes <= 0)
		return (input_bytes);

	if (bytes_read == 0)
		i = 0;

	newline_position = buffer + i;

	while (i < (size_t)input_bytes && buffer[i] != '\n')
	{
		++i;
	}

	bytes_read = i;

	free(*ptr);
	*ptr = malloc(bytes_read + 1);
	if (*ptr == NULL)
		return (-1);

	for (i = 0; i < (size_t)bytes_read; ++i)
	{
		(*ptr)[i] = *newline_position++;
	}
	(*ptr)[bytes_read] = '\0';

	return (bytes_read + 1);
}
