#include "main.h"

/**
 * _close - exits the shell with or without a return of status n
 * @arv: array of words of the entered line
 */
void _close(char **arv)
{
	int i, n;

	if (arv[1])
	{
		n = string_to_int(arv[1]);
		if (n <= -1)
			n = 2;
		free_arr(arv);
		exit(n);
	}
	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
	exit(0);
}

/**
 * string_to_int - converts a string into an integer
 *@s: pointer to a string
 *Return: the integer
 */
int string_to_int(char *s)
{
	int i, value, sign = 1;

	i = 0;
	value = 0;
	while (!((s[i] >= '0') && (s[i] <= '9')) && (s[i] != '\0'))
	{
		if (s[i] == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		value = (value * 10) + (sign * (s[i] - '0'));
		i++;
	}
	return (value);
}

/**
 * curr_env - prints the current environment
 * @arv: array of arguments
 */
void curr_env(char **arv __attribute__ ((unused)))
{

	int i;

	for (i = 0; environ[i]; i++)
	{
		_printstr(environ[i]);
		_printstr("\n");
	}

}

/**
 * change_env_status - Initialize a new environment
variable, or modify an existing one
 * @arv: array of entered words
 */
void change_env_status(char **arv)
{
	int i, j, k;

	if (!arv[1] || !arv[2])
	{
		perror(sys_env("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (arv[1][j] == environ[i][j])
		{
			while (arv[1][j])
			{
				if (arv[1][j] != environ[i][j])
					break;

				j++;
			}
			if (arv[1][j] == '\0')
			{
				k = 0;
				while (arv[2][k])
				{
					environ[i][j + 1 + k] = arv[2][k];
					k++;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{

		environ[i] = concatenate(arv[1], "=", arv[2]);
		environ[i + 1] = '\0';

	}
}

/**
 * reset_env_status - Remove an environment variable
 * @arv: array of entered words
 */
void reset_env_status(char **arv)
{
	int i, j;

	if (!arv[1])
	{
		perror(sys_env("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (arv[1][j] == environ[i][j])
		{
			while (arv[1][j])
			{
				if (arv[1][j] != environ[i][j])
					break;

				j++;
			}
			if (arv[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}

