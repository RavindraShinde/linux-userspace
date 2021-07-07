#include <stdio.h>
#include <stdlib.h>

#define ERR(fd, string) if(fd < 0) { \
				perror(string); \
				exit(0);\
			}

#define ERR_ARGC(argc, inputs, string) if(argc != inputs) { \
						perror(string);\
						exit(0); \
					}
