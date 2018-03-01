#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
int
main(int argc, char *argv [])
{
	/* close(STDOUT_FILENO); */
	int f = open("test_file.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

	int rc = fork();
	if(rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if(rc == 0)  {
		printf("child has file %d \n", f);
		write(f, "child printing\n", 16);
	} else {
		printf("parent has file %d \n", f);
		write(f, "parent printing\n", 16);
	}
	return 0;
}
