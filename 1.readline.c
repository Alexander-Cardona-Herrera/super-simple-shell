#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAXIMO 10

int main(void)
{
	ssize_t bytes_leidos;
	size_t numero_bytes;
	/*ssize_t y size_t son sinónimos de unsigned int*/
	char *cadena;
	
	puts("Por favor, introduce una línea de texto:\n");
	/* O bien, más sencillo, poner el número a 0 y la cadena a NULL, para que él mismo te haga
	la reserva necesaria */

	numero_bytes = 0;
	cadena = NULL;
	bytes_leidos = getline(&cadena, &numero_bytes, stdin);
	int s = strlen(cadena);

	if (bytes_leidos == -1)
	{
		puts("Error.");
	}

	else
	{
		puts(cadena);
	}

	free(cadena);
	return (s);
}