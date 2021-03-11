#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    pid_t pid=fork();
    int futas = 0;
    if (pid==0)
    {
        printf("Gyermek\n");
        while(futas!=5)
        {
            printf("László Andrea Neptun kód: DJ7PNE\n");
            futas++;
        }
        exit(127);
    }

    else
    {
        waitpid(pid,0,0);
        printf("Szülő\nA gyermek processz lefutott\n");
    }

    exit(0);
}
