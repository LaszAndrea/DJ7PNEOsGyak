#define KEY 654321L
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>


struct msgbuf1 {		
	long mtype;
	char mtext[512];
} *msgp, sndbuf;

struct msqid_ds ds, *buf;

int main()
{
	int msgid, msgflag, retrn, msgsize;
	key_t key =	KEY;		
	msgflag = 00666 | IPC_CREAT;
	msgid = msgget( key, msgflag);

 	if ( msgid != 0) {
                perror("Az msgget rendszerhívás nem sikerült.");
                return -1;
    }

	msgp = &sndbuf;
	msgp->mtype = 1;

    while (msg_qnum != "exit") {		
	    strcpy(msgp->mtext,"elso");
	    msgsize = strlen(msgp->mtext) + 1;

        retrn = msgsnd(msgid,(struct msgbuf *) msgp, msgsize, msgflag); 
    }

	return 0;
}
