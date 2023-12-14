#include "main.h"

/**
 * sys_env - gets the value of the global variable
 * @input_char: char of the global variable
 * Return: string
 */
char *sys_env(const char *input_char)
{
	int n, m;
	char *env;

	if (input_char == NULL)
		return (NULL);

	for (n = 0; environ[n]; n++)
	{
		m = 0;
		if (input_char[m] == environ[n][m])
		{
			while (input_char[m])
			{
				if (input_char[m] != environ[n][m])
					break;
				m++;
			}
			if (input_char[m] == '\0')
			{
				env = (environ[n] + m + 1);
				return (env);
			}
		}
	}
	return (0);
}

