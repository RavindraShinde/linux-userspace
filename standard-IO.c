#include <stdio.h>
#include <unistd.h>

int main()
{
	while(1){
		fprintf(stderr, "."); //flush the buffer immediatly
		printf("1"); //stdout, not flush until it is full or not find the newline char (\n)
		sleep(1);
	}
	return 0;
}

