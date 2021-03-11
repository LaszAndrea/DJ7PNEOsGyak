#include <stdio.h>
#include <stdlib.h>
#define ESC 27

int main()
{
    char parancs[50];
    do
    {
        printf("Adjon meg egy Unix parancsot, ctrlc-vel tud kilépni\n");
        scanf("%s", parancs);
        system(parancs);
        printf("\n");
    }while(1);

	exit(0);
}
