#include "shell.h"

/**
 * execute_log_ops - A function that executes a logical operation.
 * @left_command: The left command of the logical operation.
 * @right_command: The right command of the logical operation.
 * @operator: The logical operator ("&&" or "||").
 * Return: 0 if successful, -1 otherwise.
 **/
int execute_log_ops(char *left_command, char *right_command, char *operator)
{
	int left_result, right_result;

	/* Execute the left command */
	left_result = execute_command(left_command);
	if (_strcmp(operator, "&&") == 0)
	{
		if (left_result == 0)
		{
			right_result = execute_command(right_command);
			return (right_result);
		}
	}
	else if (_strcmp(operator, "||") == 0)
	{
		if (left_result != 0)
		{
			right_result = execute_command(right_command);
			return (right_result);
		}
	}

	return (-1);
}
