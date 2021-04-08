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

char *str_concat(char *s1, char *s2);
int _strncmp (char *s1, char *s2, size_t n);
int _path(void);
char **dividir_path(char *aux);

int contar_palabras(char *frase);

# endif
