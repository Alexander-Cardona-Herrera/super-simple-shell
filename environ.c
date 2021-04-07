#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

extern char** environ;
int _strncmp (char *s1, char *s2, size_t n);
char **dividir_comandos(char *aux);

int main (void)
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

	dividir_comandos(aux);
    return (0);
}

int _strncmp (char *s1, char *s2, size_t n)
{
	int i;

	for(int i = 0; i < n; i++)
    {
        if (s1[i] == s2[i])
        {
            if(i == (n-1))
                return 0;
        }

        int a1 = (int) s1[i];
        int a2 = (int) s2[i];
		
        if(a1 > a2)
            return 1;
        if(a2 > a1)
            return -1;
    }
}

char **dividir_comandos(char *aux)
{
	int posicion = 0;
	char **tokens = malloc(104 * sizeof(char*));
	char *token;
	token = strtok(aux, ":");

	while (token != NULL)
	{
		tokens[posicion] = token;
		printf("%s\n", token);
		posicion++;
		token = strtok(NULL, ":");
	}

	tokens[posicion] = NULL;
	return tokens;
}