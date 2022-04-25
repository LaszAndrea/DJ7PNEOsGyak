#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void alarmH(int sig)
{
    printf("DJ7PNE\nMar nincs blokkolodas!\n");
    exit(1);
}

int main(void)
{
    
    if (signal(SIGALRM, alarmH) == SIG_ERR)
    {
        printf("Nem sikerult handlert allitani!\n");
        return 1;
    }
    
    else{
        alarmH(SIGALRM);
    }

    return 0;
}
