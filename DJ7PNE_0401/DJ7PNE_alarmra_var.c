#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void do_nothing();

int main(){
    int i=1;
    unsigned sec=2;
    signal(SIGALRM, do_nothing);
    alarm(sec);
    
        printf("%d varok de meddig?\n", 1);
        pause();
       
    printf("Vegre itt az alarm\n");
    return 0;
}

void do_nothing(){
;
}
