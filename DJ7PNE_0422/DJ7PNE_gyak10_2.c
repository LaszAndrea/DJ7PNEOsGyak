#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#define MSGKEY 654321L

struct msgbuf1 {		
	long mtype;
	char mtext[512];
} sndbuf, *msgp;		

struct msqid_ds ds, *buf;

int main()
{
	int msgid, rtn, size, flag;		
	key_t key;		
	
	key = MSGKEY;
	flag = 00666 | IPC_CREAT;
	msgid = msgget( key, flag);
 	if ( msgid == -1) {
         perror("\n Az msgget sikertelen!");
         return -1;
    }

	msgp = &sndbuf;
	msgp->mtype = 1;
 	strcpy(msgp->mtext,"elso");
	size = strlen(msgp->mtext) + 1;

    rtn = msgsnd(msgid,(struct msgbuf *) msgp, size, flag);

	strcpy(msgp->mtext,"masodik");
	size = strlen(msgp->mtext) + 1;
	rtn = msgsnd(msgid,(struct msgbuf *) msgp, size, flag);
    
    if (msgp->mtext == "exit"){
        return 0;
    }
	
	key = MSGKEY;	
	flag = 00666 | IPC_CREAT | MSG_NOERROR;

	msgid = msgget(key, flag);    
 	if ( msgid == -1) {
        perror("\n Az msgget sikertelen!");
        return -1;
    }
	printf("\n Az üzenet ID: %d\n\n",msgid);

    int tipus = 0;      
	int meret = 50;
	msgp = &sndbuf;
	buf = &ds;
	rtn = msgctl(msgid,IPC_STAT,buf);
	rtn = msgrcv(msgid,(struct msgbuf *)msgp, meret, tipus, flag);
	rtn = msgctl(msgid,IPC_STAT,buf);  

    do {
        printf("\nVálasszon a menüből");
        printf("\n0. Üzenetek darabszáma");
        printf("\n1. 1db üzenet kiolvasása");
        printf("\n2. Üzenetsor megszüntetés");
        printf("\n3. Kilépés\n");
        scanf("%d", &msgid);
    }while(msgid < 0 && msgid > 1);

    if(msgid == 0){
        printf("\nüzenetek száma: %ld\n",buf->msg_qnum);
    }
    else if(msgid == 1){
        printf("\nkiküldött üzenet: %s\n", msgp->mtext);
    }
    else if(msgid == 2){
        rtn = msgctl(msgid, IPC_RMID, NULL);
        printf("\nüzenetsor megszüntetve\n");
    }
    else
        printf("viszlát");
    
    return 0;
}
