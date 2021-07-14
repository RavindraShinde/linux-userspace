#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

struct msgbuf{
	int mtype;
	char mtext[1024];
};

int main(int argc, char **argv) 
{
	if(argc != 3 ) { puts("Exception:a.out type msg"); exit(-1); }

	int id;
	struct msgbuf v;

	id = msgget(5,IPC_CREAT | 0664);
	if(id < 0) { perror("msgget"); exit(-1); }

	puts("Message queue is created");
	puts("use ipcs -q to check it");

	v.mtype = atoi(argv[1]);
	strcpy(v.mtext, argv[2]);

	msgsnd(id, &v, strlen(v.mtext)+1, 0);

	return 0;
}
