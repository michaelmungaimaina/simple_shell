#include "main.h"

/**
 * exec_cmd - a method responsible for handling
 * comand execution
 * @argv: parameter argument
 * 
 * Return: void
 */

void exec_cmd(char **argv)
{
	char *command = NULL;


	if (argv)
	{
		/* get command */
		command = argv[0];

		/* execute the command */
		if (execve(command, argv, NULL) == -1)
			perror("Error");
	}
}
