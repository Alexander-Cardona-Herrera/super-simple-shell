#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "holberton.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int _strncmp (char *s1, char *s2, size_t n);
extern char** environ;


char *read_line(void)
{
	ssize_t bytes_leidos;
	size_t numero_bytes = 0;
	char *comando = NULL;
	write(STDIN_FILENO, "#cisfun$ ", 10);

	bytes_leidos = getline(&comando, &numero_bytes, stdin);
	comando[bytes_leidos - 1] = '\0';

	if (feof(stdin))
	{
		exit(EXIT_SUCCESS);
	}

	else if (bytes_leidos == -1)
	{
		write(STDIN_FILENO, "Error.", 7);
	}
	return (comando);
}

int process_ejecutables(char **tokens)
{
	pid_t pid;
	struct stat st;
	char *token = tokens[0];
	char **paths;
	char *fullpath;
	pid = fork();
	wait(NULL);
	int i = 0;
	fullpath = _path();
	paths = dividir_path(fullpath);
	char *aux;
	
	if (pid == 0) 
	{
		if (tokens[0] != NULL && token[0] != '/')
		{
			tokens[0] = str_concat("/", tokens[0]);
			while (paths[i] != NULL)
			{
				aux = str_concat(paths[i], tokens[0]);
				if (stat(aux, &st) == 0)
				{
					execve(aux, tokens, NULL);
				}
				i++;
			}
		}
		
		else if (execve(tokens[0], tokens, environ) == -1)
		{
			perror("Error");
			exit(0);
		}
		free(paths);
	}
}

void repetir_acciones()
{
  	char *comando;
  	char **tokens;
  	int status = 1;
	
	while (status)
	{	
		comando = read_line();
		if(_strncmp(comando, "path", 5)==0)
		{
	  		_path();
		}
		tokens= dividir_comandos(comando);
			if(_strncmp(tokens[0], "exit", 5)==0)
			{
   			exit(0);
    		}
		/*	if (tokens[0] == "\n" && tokens[1] == NULL)
				read_line();*/

		status = process_ejecutables(tokens);
		free(comando);
		free(tokens);
	}
}

