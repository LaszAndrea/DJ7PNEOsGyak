#define KEY 654321L
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>


int main()
{
	int msgid, msgflag,  retrn;
	key_t key;
	key = KEY;
	msgflag = 00666 | IPC_CREAT;
	msgid = msgget(key, msgflag);
	
	retrn = msgctl(msgid, IPC_RMID, NULL);
	printf ("\nsikeres torles");

	return 0;
}
