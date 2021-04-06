#include <stdlib.h>
#include <stdio.h>
#define DELIM " \t\r\n"
#define BUF 1024
#include <string.h>
#include "holberton.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *read_line(void)
{
	ssize_t bytes_leidos;
	size_t numero_bytes = 0;
	char *comando = NULL;
	write(STDIN_FILENO, "#cisfun$ ", 10);

	bytes_leidos = getline(&comando, &numero_bytes, stdin);

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

char **dividir_comandos(char *comando)
{
	int posicion = 0;
	char **tokens = malloc(BUF * sizeof(char*));
	char *token;
	token = strtok(comando, DELIM);

	while (token != NULL)
	{
		tokens[posicion] = token;
		posicion++;
		token = strtok(NULL, DELIM);
	}

	tokens[posicion] = NULL;
	return tokens;
}

int process_ejecutables(char **tokens)
{
	pid_t pid;
	int status;
	pid = fork();

	if (pid == 0) 
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			perror("Error");
			exit(0);
		}
	}
	wait(&status);
}

void repetir_acciones()
{
  char *comando;
  char **tokens;
  int status = 1;
	do{
	comando = read_line();
	tokens= dividir_comandos(comando);
	status = process_ejecutables(tokens);
	free(comando);
	free(tokens);
	} while (status);
}
