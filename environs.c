#include "shell.h"

/**
 * print_error -  A function that prints an error message to standard error
 * @msg: The error message to be printed
 * This program conforms to the betty documentation style
 **/

void print_error(const char *msg)
{
	write(STDERR_FILENO, msg, _strlen((char *)msg));
}

/**
 * _setenv - A function that handles the setenv builtin command
 * @args: The arguments passed to the setenv command
 * Return: 1 on success, 0 on failure
 * This program conforms to the betty documentation style
 **/

int _setenv(char *args[])
{
	if (args[1] != NULL && args[2] == NULL)
	{
		/*Set environment variable with no value*/
		if (setenv(args[1], "", 1) != 0)
		{
			print_error("setenv failed\n");
			return (1);
		}
		print_environment(); /*Display the environment*/
		return (1);
	}
	else if (args[1] != NULL && args[2] != NULL)
	{
		/*Set environment variable with a value*/
		if (setenv(args[1], args[2], 1) != 0)
		{
			print_error("setenv failed\n");
			return (1);
		}
		print_environment(); /*Display the environment*/
		return (1);
	}
	else
	{
		print_error("Usage:\n");
		print_error("  setenv VARIABLE [VALUE]\n");
		return (1);
	}
}


/**
 * _unsetenv - A function that handles the unsetenv builtin command
 * @args: The arguments passed to the unsetenv command
 * Return: 1 on success, 0 on failure
 * This program conforms to the betty documentation style
 **/

int _unsetenv(char *args[])
{
	if (args[1] != NULL)
	{
		if (unsetenv(args[1]) != 0)
		{
			print_error("unsetenv failed\n");
			return (1);
		}
		return (1);
	}
	else
	{
		print_error("Usage: unsetenv VARIABLE\n");
		return (1);
	}
}

/**
 * check_builtin - Checks for a builtin command and executes it if found
 * @args: The arguments passed to the shell
 * @command_cache: The command entered by the user
 * Return: 1 if it's a builtin command, 0 otherwise
 * This program conforms to the betty documentation style
 **/

int check_builtin(char *args[], char *command_cache)
{
	int status;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			status = _atoi(args[1]);
			my_exit(command_cache, status);
		}
		else
		{
			my_exit(command_cache, 0);
		}
		return (1);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		print_environment();
		return (1);
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		return (_setenv(args));
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		return (_unsetenv(args));
	}

	return (0);
}
