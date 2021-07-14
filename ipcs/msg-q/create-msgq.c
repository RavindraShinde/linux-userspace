#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int id;

	id = msgget(5,IPC_CREAT | 0664);
	if(id < 0) { perror("msgget"); exit(-1); }

	puts("Message queue is created");
	puts("use ipcs -q to check it");

	return 0;
}
