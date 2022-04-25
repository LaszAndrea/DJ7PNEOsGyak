#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

sem_t m;

void* thread(void* arg)
{
    sem_wait(&m);
    printf("A pidem: %d\n", getpid());
    sleep(1);
    sem_post(&m);
}

int main()
{
    sem_init(&m, 0, 2);
    pthread_t h1,h2,h3;
    pthread_create(&h1, NULL, thread,NULL);
    pthread_create(&h2, NULL, thread,NULL);
	pthread_create(&h3, NULL, thread,NULL);
    pthread_join(h1,NULL);
    pthread_join(h2,NULL);
	pthread_join(h3,NULL);
    sem_destroy(&m);

    return 0;
}
