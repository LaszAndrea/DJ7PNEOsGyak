#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void tHandler(int sig)
{
    signal(sig, SIG_IGN);
    printf("SIGTERM: %d\n", sig);
}

int main(void)
{
    if (signal(SIGTERM, tHandler) == SIG_ERR)
    {
        printf("Nem sikerult handlert allitani!\n");
        return 1;
    }

    while(1)
    {
        printf("Varakozas\n");
        sleep(3);
    }

    return 0;
}

