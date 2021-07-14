#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUF_SIZE 100

int main() {
	int fd[2];
	char buf[BUF_SIZE];

	mkfifo("channel1", 0664); //< 0) { perror("mkfifo"); exit(0); }
	mkfifo("channel2", 0664); //< 0) { perror("mkfifo"); exit(0); }
	
	fd[1] = open("./channel1", O_RDONLY );
	if(fd[1] < 0) { perror("open"); exit(0); }
	puts("opened the write only channel1");

	fd[0] = open("./channel2", O_WRONLY );
	if(fd[0] < 0) { perror("open"); exit(0); }
	puts("opened the read only channel1");

	while(1){
		puts("clearing buffer");
		bzero(buf, sizeof(buf));
		puts("process1<:");
		read(fd[1], buf, sizeof(buf));
		puts(buf);

		printf("process2>:");
		bzero(buf, sizeof(buf));
		scanf(" %[^\n]", buf);
		write(fd[0], buf, strlen(buf)+1);
	}
	
	return 0;
}
