#include "main.h"

/**
 * execute - executes a command
 * @argv: array of arguments
 */

void execute(char **argv)
{

	int child_id, par_stat;

	if (!argv || !argv[0])
		return;
	child_id = fork();
	if (child_id == -1)
	{
		perror(sys_env("_"));
	}
	if (child_id == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&par_stat);
}

