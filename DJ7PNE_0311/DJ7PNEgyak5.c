#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int stat;
    pid_t pid;

    if ((pid = fork()) == -1)
    {
        perror("nem jó");
    }
    else if ((stat = execl("/bin/man", "man", NULL)) < 0)
    {
        perror("system() error");
    }
    if (WIFEXITED(stat))
    {
        printf("Normális, visszatérési érték = %d\n", WEXITSTATUS(stat));
    }
    if ((pid = fork()) == -1)
    {
        perror("Hiba");
    }
    else if ( (stat = system("nem jó")) < 0)
    {
        perror("system() error");
    }
    if(WIFEXITED(stat))
    {
        printf("Nem normális befejeződés, visszatérési érték = %d\n", WEXITSTATUS(stat));
    }
    else
    {
        waitpid(pid,0,0);
        printf("\nA gyermek processz lefutott\n");
    }


    exit(0);
}
