#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "holberton.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char** environ;

int _path(void)
{
    int i = 0;
    char *aux = NULL;

    while (environ[i] != NULL)
    {
        if (!_strncmp(environ[i], "PATH=", 5))
        {
            aux = environ[i] + 5;
        }
        i++;
    }

    dividir_path(aux);
}

char *str_concat(char *s1, char *s2)
{
	char *aux;
	int i, j, k;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
	{
	}
	i++;

	for (k = 0; s2[k] != '\0'; k++)
	{
	}
	k++;

	aux = malloc((i + k - 1) * sizeof(char));

	if (!aux)
		return (NULL);

	for (j = 0; s1[j] != '\0'; j++)
		aux[j] = s1[j];

	for (j = 0; s2[j] != '\0'; j++)
		aux[i - 1 + j] = s2[j];

	return (aux);
}
char **dividir_path(char *aux)
{

	int posicion = 0;
    int i;
    int conteo = 1;
    char *path;

    for(i = 0; aux[i] != '\0'; i++)
        if (aux[i] == ':')
            conteo++;

	char **paths = malloc((conteo + 1) * sizeof(char*));
	path = strtok(aux, ":");

	while (path != NULL)
	{
		paths[posicion] = path;
		printf("%s\n", path);
		posicion++;
		path = strtok(NULL, ":");
	}

	paths[posicion] = NULL;
    repetir_acciones();
}

int contar_palabras(char *frase)
{
	int i, count = 0;

    for (i = 0; frase[i]; i++)
    {
        if (frase[i] == 32 && frase[i + 1] != 32 && frase[i + 1] != 0)
            count++;
    }

    if (frase[0] != 32)
        count++;

    return (count);
}
