#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdarg.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

/**
 * struct builtins - builtin command and functions for shell
 * @cmd: cmd name
 * @f: pointer to builtin functions
 *
 * Description: struct for builtin functions
 */
typedef struct builtins
{
	char *cmd;
	int (*f)(char **args, char **env);
} built_cmd;

int prompt(char **pointer);
int _atoi(char *s);
int my_strlen(const char *s);
int str_cmp(const char *s1, const char *s2);
int strn_cmp(const char *s1, const char *s2);
char **_strntok(char *s);
void word_finder(char **array, char *s);
int word_length(char *s);
void string_cpy(int dest, char *s, char **mem);
char *string_concat(char *s1, char *s2);
int executeEnvVar(char **args, char **env);
int our_exit(char **args, char **env);
int execute_builtin_cmd(char **args, char **env);
void clear_array(char **ar);
void clear_string(int, const unsigned int n, ...);
char *_memcpy(char *dest, char *src, unsigned int n);
char *get_env(const char *var_name, char **env);
void path_finder(char **s, char **env);
void prompt_signal(int sign);
void e_exit(char *, int stat);
#endif

