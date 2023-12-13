#include "shell.h"
/**
 * main - shell
 *
 * Return: 0
 */
int main(void)
{
	char *prompt = "$ ";
	char *command_cache = NULL;
	size_t command_bytes = 0;
	ssize_t command;
	int result;
	bool mode_switch = 0;

	while (1 && !mode_switch)
	{
		if (!isatty(STDIN_FILENO))
			mode_switch = 1;
		if (!mode_switch)
			write(STDOUT_FILENO, prompt, PROMPT_SIZE);

		command = read_command(&command_cache, &command_bytes);

		if (command == -1)
		{
			perror("Read command failed");
			cleanup(command_cache);
			return (-1);
		}

		if (command_cache[command - 1] == '\n')
		{
			command_cache[command - 1] = '\0';
		}

		result = execute_command(command_cache);

		if (result == -1)
		{
			cleanup(command_cache);
			exit(EXIT_FAILURE);
		}
	}
	cleanup(command_cache);
	exit(EXIT_SUCCESS);
}
