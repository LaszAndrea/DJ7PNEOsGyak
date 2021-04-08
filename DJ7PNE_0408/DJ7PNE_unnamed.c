#include<stdio.h>
#include<unistd.h>

int main(){

    int fd[2];
    int child;

    if(pipe(fd)){
        perror("pipe error");    
        return 1;
    }

    child=fork();

    if(child > 0){
        char szoveg[500];
        close(fd[1]);
        read(fd[0],szoveg,sizeof(szoveg));
        printf("%s",szoveg);


        close(fd[0]);
    }
    else if(child==0){
        close(fd[0]);
        write(fd[1],"Laszlo Andrea DJ7PNE", 40);
        close(fd[1]);
    }

    return 0;
}
