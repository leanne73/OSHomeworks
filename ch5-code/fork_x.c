#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
int
main(int argc, char *argv [])
{
	int x = 100;

	int rc = fork();
	if(rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if(rc == 0)  {
		x = x + 7;
		printf("child says x is %d\n", x);
	} else {
		x = x - 5;
		printf("parent says x is %d\n", x);
	}
	return 0;
}
