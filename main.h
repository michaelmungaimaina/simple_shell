#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

void inter_sig(int sig_num);
void end_of_file(int len, char *buff);
void _isatty(void);
int _putchar(char c);
void _printstr(char *str);
int str_len_func(char *s);
char *dup_str(char *string);
char *concatenate(char *str1, char *str2, char *str3);

char **seg_str(char *str, const char *delim);
void execute(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

extern char **environ;

/**
 * struct path_list - Linked list containing PATH directories
 * @dir: directory in path
 * @p: pointer to next node
 */
typedef struct path_list
{
	char *dir;
	struct path_list *p;
} path_list;

char *sys_env(const char *name);
path_list *new_end_node(path_list **head, char *str);
path_list *path_join(char *path);
char *path_search(char *filename, path_list *head);

/**
 * struct built_cmd - pointer to function with corresponding builtin command
 * @name: buildin command
 * @func: execute the buildin command
 */
typedef struct built_cmd
{
	char *name;
	void (*func)(char **);
} built_cmd;

char *str_copy(char *dest, char *src);
void(*check_cmd(char **arv))(char **arv);
int string_to_int(char *s);
void _close(char **arv);
void curr_env(char **arv);
void change_env_status(char **arv);
void reset_env_status(char **arv);

void free_arr(char **arv);
void free_path_list(path_list *head);

#endif
