#include <stdio.h>
/* 
 * The ENVIRON variable contains the environment.
 *
 */

extern char** environ;


int main ()
{
	char** var;
	for (var = environ; *var != NULL; ++var)
		printf ("%s\n", *var);

	char *tmp;
       
	tmp = getenv("PATH");
	printf("PATH-%s\n", tmp);

	tmp = getenv("USER");
	printf("USER-%s\n", tmp);

	return 0;
}


/*
 * access env vaiables - getenv()
 * set env variables - setenv()
 * remove the env variables - unsetenv()
 *
 */
