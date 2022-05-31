#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

  int pid = fork();

  /* child process */
  if (pid == 0)
    {
     
      printf ("\nProceso Hijo! [%d]  \n",getpid());
       sleep(1);
    }
  /* parent process */
  else
    {
        printf ("\nProceso padre! [%d] \n",getpid());
        sleep(20);
    }

    printf( "\nProceso [%d] terminó   \n",getpid());
}