#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHMKEY 13

int main()
{
  int shmid, flag, rtn, choose;
  int size = 512;
  key_t key;

  key = SHMKEY;
  flag = 0;

  if((shmid = shmget(key, size, flag)) < 0)
  {
     flag = 00666 | IPC_CREAT;
     if((shmid = shmget(key, size, flag)) < 0)
     {
        perror("\nSikertelen shmget!");
        return -1;
     }
  }

  printf("\nAz azonosító : %d\n", shmid);

	return 0;
}
