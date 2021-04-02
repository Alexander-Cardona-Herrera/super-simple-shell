#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - starting point
 * @ac: number of strings
 * @av: strings
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int main(int ac, char *av[])
{
	int i;

	for (i = 0; av[i] != NULL; i++)
		printf("%s\n", av[i]);

	return (0);
}
