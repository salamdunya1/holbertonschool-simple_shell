#ifndef __SIMPLE__SHELL__H__
#define __SIMPLE__SHELL__H__

#define MAX_ARGS 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>

extern char **environ;

char **get_argument(char *line);
char *get_path(char *line);
void free_args(char **array_command);
void execute_command(char **array_command, int nbr_command);
char *_getenv(const char *name);


int _execute(char *arguments, struct stat *statbuf, char **envp);
bool check_file_status(char *pathname, struct stat *statbuf);
void handle_error(pid_t pid);

char **split_string(const char *str, const char *delim, int *argc);

unsigned int count_words(const char *str, const char *delimiters, unsigned int *word_sizes);
bool is_delimiter(char c, const char *delimiters);
void set_zeros(unsigned int *arr, size_t size);
void free_vector(char **vector, int size);

#endif
