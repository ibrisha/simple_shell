#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

/* included standard library headers */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <signal.h>

/* included custom headers */
#include "structs.h"

/* -----MACROS----- */
#define BUFSIZE 1024
#define EXT_SUCCESS 0
#define EXT_FAILURE 1
#define TRUE (1 == 1)
#define FALSE (!TRUE)

/* this defines the macros for token_t struct */
#define TOKEN_STRING     0
#define TOKEN_SEMICOLON  1
#define TOKEN_PIPE       2
#define TOKEN_REWRITE    3
#define TOKEN_APPEND     4
#define TOKEN_CAT        5
#define TOKEN_BACKGROUND 6
#define TOKEN_AND        7
#define TOKEN_OR         8

/* -----environ----- */
extern char **environ;

/* ---------------main--------------- */
ssize_t _getline(char **buffer, size_t *limit);
int _filemode(int fd);
ssize_t _readline(int fd, char **buffer, size_t *limit);

/* --------- arguments inventory ---------- */
arg_inventory_t *buildarginv(void);
char *set_name(env_t *envlist, char *name);

/* ---------------execute--------------- */
pid_t execute(arg_inventory_t *arginv);
int exec_builtins(arg_inventory_t *arginv);
pid_t exec_path(char *command, arg_inventory_t *arginv);
/*void safe_dup2(int new_fd, int old_fd);*/
/* int redirect_output(arg_inventory_t *arginv, int close_dup); */
/* int redirect_input(arg_inventory_t *arginv); */

/* ---------------tokenizer--------------- */
int delete_tokens(tokens_t *tokens);
