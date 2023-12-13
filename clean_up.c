#include "shell.h"

/**
 * cleanup - A function that cleans up the allocated memory
 * @command_cache: the memory to free
 * Return: nothing
 **/

void cleanup(char *command_cache)
{
	free(command_cache);
}
