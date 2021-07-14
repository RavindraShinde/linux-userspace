#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/stat.h>
#include <sys/types.h>

int main() {
	int fd ;

	if( mkfifo("channel", 0664) < 0) { perror("mkfifo"); exit(0); }
	
	fd = open("./channel", O_RDONLY);
	if(fd < 0) { perror("open"); exit(0); }

	printf("Created named pipe\n");

	return 0;
}
