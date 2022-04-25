#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHMKEY 13

struct shmid_ds shmid_ds, *buf;

int main()
{
  int schmid, flag, rtn;
  key_t key;
  int size = 512;

  buf = &shmid_ds;
  key = SHMKEY;
  flag = 0;

  if((schmid = shmget(key, size, flag)) < 0)
  {
     perror("\n Sikertelen shmget!\n");
     return -1;
  }
    rtn = shmctl(schmid, IPC_STAT, buf);
    printf("\n meret: %ld", buf->shm_segsz);
    printf("\n pid: %d\n", buf->shm_lpid);


  return 0;
}
