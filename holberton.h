# ifndef HOLBERTON_H
# define HOLBERTON_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/wait.h>

char **dividir_comandos(char *comando);
int process_ejecutables(char **tokens);
char *read_line(void);
void repetir_acciones(void);

# endif
