#include "shell.h"

/**
 * execute_child - A function that executes the child process
 * @args: pointer to the argument count
 * Return: 0 if successful
 * This program conforms to the betty documentation style
 **/

int execute_child(char *args[])
{
	char *path = getenv("PATH");
	char *directories, *directory;

	if (path == NULL)
	{
		perror("PATH environment variable not set");
		return (-1);
	}
	directories = _strdup(path);

	if (directories == NULL)
	{
		perror("Memory allocation error");
		return (-1);
	}
	directory = _strtok(directories, ":");

	while (directory != NULL)
	{
		if (construct_and_execute(directory, args) == 0)
		{
			free(directories);
			return (0);
		}
		directory = _strtok(NULL, ":");
	}
	perror("Execve failed");
	free(directories);
	return (-1);
}


/**
 * execute_parent - function to keep parent process on hold until child execute
 * @pid: the child process id
 * Return: 0 if successful, -1 otherwise
 */
int execute_parent(pid_t pid)
{
	int status;
	int wait_result = waitpid(pid, &status, 0);

	if (wait_result == -1)
	{
		perror("waitpid failed");
		return (-1);
	}

	return (0);
}

/**
 * execute_command - function to execute the command entered
 * @command_cache: command entered by users
 * Return: the pid of the calling process
 */

int execute_command(char *command_cache)
{
	char *args[MAX_ARGUMENTS];
	pid_t pid;
	int exec_result;

	if (prepare_command_args(command_cache, args) == -1)
		return (-1);
	if (check_builtin(args, command_cache))
	{
		return (0);
	}

	pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		return (-1);
	}
	else if (pid == 0)
	{
		exec_result = execute_child(args);

		if (exec_result == -1)
		{
			my_exit(command_cache, 0);
		}
		return (exec_result);
	}
	else
	{
		return (execute_parent(pid));
	}
}
