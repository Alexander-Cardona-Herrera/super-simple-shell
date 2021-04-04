#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
  
int main()
{

  int status;
char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

for(int i = 0; i < 5 ;i++)
{
		if(fork() == 0)
		{
            printf("[soy] pid %d de [parent] pid %d\n",getpid(),getppid());
            if (execve(argv[0], argv, NULL) == -1)
                perror("Error");

            exit(0);
        }
		for(int i = 0; i < 5 ;i++)
		  wait(&status);
    }	
    return (0);
}
