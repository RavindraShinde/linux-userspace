#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "macros.h"

/* Information
*  
* O_RDONLY, O_WRONLY, O_RDWR - mandatory 
* O_CREAT, O_APPEND, O_TRUNC, O_EXCL - optional
*
*/

//#define ERR(fd, string) if(fd < 0) { \
//				perror(string); \
//				exit(0);\
//			}

int main(int argc, char **argv)
{
	ERR_ARGC(argc, 3, "Exceprion: <a.out> <source-file> <dest-file>");

	int fd_src, fd_dest;
	char buf;

	fd_src = open( argv[1], O_RDONLY, 0664);
	ERR(fd_src, "open");

	fd_dest = open(argv[2], O_WRONLY | O_CREAT, 0664);
	ERR(fd_src, "open");

	while( read(fd_src, &buf, 1) > 0 ) {

		if(write(fd_dest, &buf, 1) < 0) {
			perror("write");
			exit(0);
		}
	}

	close(fd_src);
	close(fd_dest);

	puts("File copyied ...");

	return 0;
}
