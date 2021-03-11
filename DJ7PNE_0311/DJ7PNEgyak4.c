#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
     pid_t pid;
     if ((pid = fork()) == -1)
     {
        perror("nem jó");
     }
     else if (pid == 0)
     {
        execl("/bin/man", "man", "man", NULL);
        printf("execl hiba.\n");
     }

    else
    {
        waitpid(pid,0,0);
        printf("\nA gyermek processz lefutott\n");
    }
    return 0;
}
