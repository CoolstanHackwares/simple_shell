#include "shell.h"
/**
 * my_exit - A function that exits the simple shell
 * @command_cache: the command entered
 * @status: exit status
 * Return: nothing
 */

void my_exit(char *command_cache, int status)
{
	cleanup(command_cache);
	exit(status);
}


/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 * Return: s1[i] - s2[i]
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}


/**
 *   _strcpy - Copy a string
 *   @dest: Destination value
 *   @src: Source value
 *   Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i++] = '\0';
	return (dest);
}
