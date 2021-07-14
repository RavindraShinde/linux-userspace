#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024
#define MSG_EXCEPT 020000
struct msgbuf{
	int mtype;
	char mtext[1024];
};

int main(int argc, char **argv) 
{
	if(argc != 3 ) { puts("Exception:a.out key type"); exit(-1); }

	int id;
	struct msgbuf v;

	id = msgget(atoi(argv[1]),IPC_CREAT | 0664);
	if(id < 0) { perror("msgget"); exit(-1); }

	puts("Message queue is created");
	puts("use ipcs -q to check it");

	v.mtype = atoi(argv[1]);

	while(1){
		bzero(v.mtext, sizeof(v.mtext));
		puts("Message from Server");
		msgrcv(id, &v, sizeof(v.mtext), atoi(argv[2]), MSG_EXCEPT );
		printf("Type[%d]: msg-%s\n", v.mtype, v.mtext);

		puts("Message to server");
		bzero(v.mtext, sizeof(v.mtext));
		scanf(" %[^\n]", v.mtext);
	//	if(strncmp(v.text, "exit")) exit(-1);
		msgsnd(id, &v, strlen(v.mtext)+1, 0);
	}

	return 0;
}
