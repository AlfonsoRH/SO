
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

  int pid = fork();


  if (pid == 0)
    {
      printf ("\n Hijo: %d Matar a padre:  %d \n",getpid(),getppid());
      kill (getppid(), 9);
    }

  else
    {
      printf ("\nProceso padre!\n");
      wait(0);
    
    }

    printf( "\nProceso padre muerto, Proceso hijo:  %d \n",getpid());
}