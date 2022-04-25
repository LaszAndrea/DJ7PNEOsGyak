#define KEY 654321L
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

struct msgbuf1 {
	long tipus;
	char mtext[512];
} rcvbuf, *msgp;		

struct msqid_ds ds, *buf;

int main()
{
	int msgid, type, msgflag, retrn, size;
	key_t key;		
	key = KEY;
	msgflag = 00666 | IPC_CREAT | MSG_NOERROR;
    msgid = msgget(key, msgflag);    
 	if ( msgid != 0) {
        perror("A rendszerhívás nem sikerült.");
        return -1;
    }

	msgp = &rcvbuf;
	buf = &ds;
	size = 20;
	type = 0;
	retrn = msgctl(msgid,IPC_STAT,buf);
	printf("Az uzenetek szama: %ld",buf->msg_qnum);
	
	while (buf->msg_qnum) {		
	    retrn = msgrcv(msgid,(struct msgbuf *)msgp, size, type, msgflag);
	    printf("\naz uzenet:%s\n",msgp->mtext);
	    retrn = msgctl(msgid,IPC_STAT,buf);  
    }

	return 0;
}
