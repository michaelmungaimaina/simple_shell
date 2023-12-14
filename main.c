#include "main.h"

/**
 * main - beginning of file excecution
 * Return: 0 on success
 */

int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, *value, *pathname, **arv;
	size_t size = 0;
	path_list *head = '\0';
	void (*f)(char **);

	signal(SIGINT, inter_sig);
	while (len != EOF)
	{
		_isatty();
		len = getline(&buff, &size, stdin);
		end_of_file(len, buff);
		arv = seg_str(buff, " \n");
		if (!arv || !arv[0])
			execute(arv);
		else
		{
			value = sys_env("PATH");
			head = path_join(value);
			pathname = path_search(arv[0], head);
			f = check_cmd(arv);
			if (f)
			{
				free(buff);
				f(arv);
			}
			else if (!pathname)
				execute(arv);
			else if (pathname)
			{
				free(arv[0]);
				arv[0] = pathname;
				execute(arv);
			}
		}
	}
	free_path_list(head);
	free_arr(arv);
	free(buff);
	return (0);
}

