#include "main.h"

/**
 * inter_sig - checks if Ctrl C is pressed
 * @sig_num: int
 */
void inter_sig(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_printstr("\n#cisfun$ ");
	}
}

/**
* end_of_file - handles the End of File
* @len: return value of getline function
* @buff: buffer
 */
void end_of_file(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_printstr("\n");
			free(buff);
		}
		exit(0);
	}
}
/**
  * _isatty - verif if terminal
  */

void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_printstr("#cisfun$ ");
}
