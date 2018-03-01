#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
int
main(int argc, char *argv [])
{
	int f = open("test_file.txt", O_CREAT|O_RDWR|O_TRUNC, S_IRWXU);

        int rc = fork();
        if(rc < 0) {
                fprintf(stderr, "fork failed\n");
                exit(1);
        } else if(rc == 0)  {
                printf("hello\n");
		int w = write(f, "child done\n", 11);
        } else {
		int f2 = open("test_file.txt", O_CREAT|O_RDWR|O_TRUNC, S_IRWXU);
		char text[10];
		while(read(f2, text, 10) < 10) { };
                printf("goodbye\n");
        }
        return 0;
}
