#include "shell.h"

/**
 * _strlen - A function that calculates the length of a string
 * @s: the pointer to the string
 * Return: The length of the string
 * This program conforms to the betty documentation style
 **/

int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}

/**
 * _strchr - function that searches for a character in a string
 * @s: A pointer to the string to search
 * @c: the charcter to search for
 * Return: a pointer to the first occurence of the character ch
 * in the string or NULL if the character is not found
 * This program conforms to the betty documentation style
 **/

char *_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}

	return ('\0');
}

/**
 * _strtok - A function that tokenizes a string
 * @s: the string to tokenize
 * @del: the delimiter characters
 * Return: pointer to the next token in the string or NULL if
 * no tokens are found
 * This program conforms to the betty documentation style
 **/

char *_strtok(char *s, const char *del)
{
	static char *l_tok = '\0';
	char *tok;

	if (s != NULL)
	{
		l_tok = s;
	}

	if (l_tok == NULL)
	{
		return (NULL);
	}

	tok = l_tok;

	for (tok = l_tok; *l_tok != '\0'; l_tok++)
	{
		if (_strchr(del, *l_tok) != NULL)
		{
			*l_tok = '\0';
			l_tok++;
			return (tok);
		}
	}

	if (*tok == '\0')
	{
		l_tok = NULL;
		return (NULL);
	}

	return (tok);
}

/**
 * _atoi - A function that converts a string to an integer
 * @s: The string to be converted
 * Return: the int converted from the string
 * This program conforms to the betty documentation style
 **/

int _atoi(char *s)
{	
	int a, n, x;

	a = n = 0;
	x = 1;

	while (s[a] != '\0')
	{
		if (s[a] == '-')
		{
			x *= -1;
		}
		else if (s[a] >= '0' && s[a] <= '9')
		{
			n = (n * 10) + x * ((s[a]) - '0');
		}
		a++;
	}
	return (n);
}
