#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>
#include <stdlib.h>

int main()
{
	int child;
    int stat=0;
	double begin=clock();

	child=fork();

	if(child==0){
		system("/bin/ls -R");
		sleep(1);
		exit(1);
	}

	else
    {
		wait(&stat);
		if (WIFEXITED(stat))
        {
            printf("Normális eset, visszatérési értéke = %d\n", WEXITSTATUS(stat));
        }
	}

	double end=clock();
	printf("futott %.2f\n",(end-begin));

	return 0;
	
}



















