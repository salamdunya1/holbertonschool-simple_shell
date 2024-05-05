// #define _GNU_SOURCE
// #include "simple_shell.h"

// /**
//  * main - write a UNIX command line interpreter
//  * @argc: number of argument
//  * @argv: contain the name of programm
//  * Return: Always 0 (success)
//  */

// int main(__attribute__((unused)) int argc, char *argv[])
// {
// 	int nbr_command = 0;
// 	char *line = NULL, **array_command = NULL;
// 	size_t length = 0;
// 	ssize_t bytes_read;

// 	while (1)
// 	{
// 		if (isatty(STDIN_FILENO))
// 			printf("$ ");
// 		nbr_command++;
// 		bytes_read = getline(&line, &length, stdin);
// 		if (bytes_read == -1)
// 		{
// 			if (feof(stdin))
// 			{
// 				if (isatty(STDIN_FILENO))
// 					printf("\n");
// 				fflush(stdout);
// 				break;
// 			}
// 			perror(argv[0]), free(line);
// 			continue;
// 		}
// 		line[bytes_read - 1] = '\0';
// 		if (strcmp(line, "exit") == 0)
// 			break;
// 		array_command = get_argument(line);
// 		if (array_command[0] == NULL)
// 		{
// 			free_args(array_command), free(line);
// 			line = NULL;
// 			continue;
// 		}
// 		execute_command(array_command, nbr_command);
// 		free_args(array_command);
// 	}
// 	free(line);
// 	return (0);
// }


#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - super simple shell program that runs shell command
 * 
 * When this program is compiled and executed, creates a to process
 * and runs the getline system call and reads the input from stdio.
 * This input should be the path to an executable.
 * 
 * Return: Always 0.
*/

int main(int argc, char *argv[], char **env)
{
    char *buff = NULL, *prompt = "$ ";
	size_t buff_size = 0;
	ssize_t bytes;
	pid_t wpid;
	int wstatus;
	bool from_pipe = false;
	struct stat statbuf;

	while (1 && !from_pipe)
	{
		if (isatty(STDERR_FILENO) == 0)
		    from_pipe = true;

		write(STDOUT_FILENO, prompt, 2);

		bytes = getline(&buff, &buff_size, stdin);
		if (bytes == -1)
		{
			perror("Error (getline)");
			free(buff);
			exit(EXIT_FAILURE);
		}
		
		if(buff[bytes - 1] == '\n')
		   buff[bytes - 1] = '\0';


		wpid = fork();
		if (wpid == -1)
		{
			perror("Error (fork)");
			exit(EXIT_FAILURE);
		}
		if (wpid == 0)
		   _execute(buff, &statbuf, env);

		if (waitpid(wpid, &wstatus, 0) == -1)
		{
			perror("Error (wait)");
			exit(EXIT_FAILURE);
		}   
		
	}
	free(buff);
	return (0);

}

int _execute(char *arguments, struct stat *statbuf, char **envp)
{
	int argc;
	char **argv;
	char *exe;

	argv = split_string(arguments, " ", &argc);

	if (!check_file_status(argv[0], statbuf))
	{
		perror("Error (file status)");
		exit(EXIT_FAILURE);
	}

	execve(argv[0], argv, envp);


	/* Free the dynamically allocated argv array */
	/* free_vector(argv, 20) */

	/* Id execve failed */
	perror("Error (execve)");
	exit(EXIT_FAILURE);
	
}

bool check_file_status(char *pathname, struct stat *statbuf)
{
	int stat_return;

	stat_return = stat(pathname, statbuf);

	if(stat_return == 0)
	   return (true);

	return (false);   
}

void handle_error(pid_t pid)
{
	if(pid == -1)
	{
		printf("Error");
		exit(EXIT_FAILURE);
	}

}

