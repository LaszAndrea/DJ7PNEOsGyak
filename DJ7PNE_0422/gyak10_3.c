#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHMKEY 13
#include <string.h>

struct str {
    int lng;
    char text[512-sizeof(int)];
} *segment;

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

  flag = 00666 | SHM_RND;
  segment = (struct str *)shmat(shmid, NULL, flag);

  if(segment == (void *) - 1)
  {
     perror("\n sikertelen csatlakozas");
     return -1;
  }

  if(strlen(segment->text) > 0)
  {
     printf("\nregi szoveg : %s", segment->text);
  }
    
  printf("\nuj szoveget : ");
  scanf("%s", segment->text);
  printf("\nAz uj szoveg: %s \n", segment->text);

  shmdt(segment);
  struct shmid_ds shmid_ds, *buf;
  buf = &shmid_ds;
  flag = 0;

  do {
    printf("Valasszon a menubol\n");
    printf("0. status lekerese\n");
    printf("1. memoria torlese\n");
    scanf("%d", &choose);

  }while(choose != 0 && choose != 1);

  if(choose == 0){
    rtn = shmctl(shmid, IPC_STAT, buf);
    printf("\nmeret: %ld", buf->shm_segsz);
    printf("\npid: %d\n", buf->shm_lpid);
  }
  else if(choose == 1){
    rtn = shmctl(shmid, IPC_RMID, NULL);
    printf("\nszegmens megszüntetve\n");
  }

  return 0;
}
