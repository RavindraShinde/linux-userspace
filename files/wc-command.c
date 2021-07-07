#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "macros.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
	ERR_ARGC(argc, 2, "Exception: <a.out> <file-name>");

	int fd, words, chars, lines;
	char ch;

	fd = open(argv[1], O_RDONLY, 0664);
	ERR(fd, "open");

	chars = lines = words = 0;

	while( read(fd, &ch, 1) > 0){
		chars++;
		if(ch == '\n') lines++;
		if(ch == ' ' || ch == '\n') words++;
	}

	printf("%s: %d %d %d\n", argv[1], chars, words, lines);
	return 0;

}
