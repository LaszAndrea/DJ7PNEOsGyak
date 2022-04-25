#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int interrupt = 0;

void interruptH(int signal){
    printf("\nSIGINT: %d", signal);
    interrupt++;
}

void quitH(int signal){
    printf("\nSIGQUIT: %d", signal);
}

int main(void)
{
    int sec = 1;

    if ((signal(SIGINT, interruptH)) == SIG_ERR){
        printf("Nem sikerult handlert allitani a SIGINT jelre.\n");
        return -1;
    }

    if ((signal(SIGQUIT, quitH)) == SIG_ERR){
        printf("Nem sikerult handlert allitani a SIGQUIT jelre.\n");
        return -1;
    }

    do{
        printf("Varakozas\n");
        sleep(sec);
    }while(interrupt<2);

    printf("\nMegerkezett mind a ketto SIGINT jel is.\n");
    return 0;
}

