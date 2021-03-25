#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    int p;
    int elozo;
    char buff[100];
    buff[0] = 0;

    p = open("DJ7PNE.txt", O_RDWR);

    if (p==-1)
    {
        perror("Fajl megnyitasa soran [open()] hiba lepett fel!\n");
        exit(-1);
    }
    else
    {
        printf("A fajlt megnyitottam olvasasra\n");
    }

    elozo = read(p, buff, 50);
    printf("Beolvasott uzenet %s\n", buff);
    printf("A read() %d byteot olvasott.\n", elozo);
    strcpy(buff, "DJ7PNE");

    elozo = lseek(p, 0, SEEK_SET);
    printf("Az lseek() beallt a %d. helyre", elozo);

    elozo = write(p, buff, 6);
    printf("\nIde a write() %d byteot irt: %s\n", elozo, buff);
    close(p);

    return 0;
}
