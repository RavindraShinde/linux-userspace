#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
	int fd1, fd2;
	fd1 = open("./copy-file.txt", O_RDONLY, 0660);
	if(fd1 < 0) {
		perror("open");
		exit(0);
	}

	fd2 = open("./copied.txt", O_CREAT | O_WRONLY | O_TRUNK, 0660);
	if(fd2 < 0){
		perror("open");
		exit(0);
	}



	do{
		
	}
	while()

	return 0;
}
