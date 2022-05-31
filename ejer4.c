#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("Proceso padre [%d]\n", getpid());

    for (int i = 0; i < 2; i++)
    {
        if (fork() == 0)
        {
            printf("Proceso hijo [%d] hijo de  [%d]\n", getpid(), getppid());
            for (int j = 0; j < 3; j++)
            {
                if (fork() == 0)
                {
                    printf("Proceso hijo [%d] hijo de [%d]\n", getpid(), getppid());
                    sleep(20);
                    exit(1);
                }
            }

            sleep(20);
            exit(1);
        }
    }
    sleep(5);
    kill(getpid(),SIGUSR1);
}