#include <stdio.h>
#include <stdlib.h>

int main()
{
	int ret_val;
	ret_val = system("ls -lrt /");

	return ret_val;
}
