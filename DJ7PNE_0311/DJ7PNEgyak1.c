#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int	stat;
	if ((stat = system("man")) < 0)
	{
		perror("system() error");
    }
	if (WIFEXITED(stat))
	{
		printf("Első eset normális, visszatérési értéke = %d\n", WEXITSTATUS(stat));
    }
    if ((stat = system("nem")) < 0)
		{
            perror("system() error");
        }
	if (WIFEXITED(stat))
        {
            printf("Második eset nem normális végződés, visszatérési értéke = %d\n", WEXITSTATUS(stat));
        }


	exit(0);
}
