#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

void ls_execvp();
void ls_execv();
void ls_execlp();
void ls_execl();
void ls_execvpe();
void ls_execle();

int
main(int argc, char *argv [])
{
	int rc = fork();
	if(rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if(rc == 0)  {
		ls_execv();
	} else {
	}
	return 0;
}

void ls_execvp()
{
	printf("using execvp\n");
	char *myargs[2];
        myargs[0] = "ls";
	myargs[1] = NULL;
        execvp(myargs[0], myargs);
}

void ls_execv()
{
	printf("using execv\n");
	char *myargs[3];
        myargs[0] = "/bin/ls";
        myargs[1] = ".";
        myargs[2] = NULL;
	execv(myargs[0], myargs);
}

void ls_execlp()
{
	printf("using execlp\n");
        char *myargs[2];
	myargs[0] = "ls";
	myargs[1] = NULL;
        execlp(myargs[0], myargs[0]);
}

void ls_execl()
{
	printf("using execl\n");
	char *myargs[3];
	myargs[0] = "/bin/ls";
	myargs[1] = ".";
	myargs[2] = NULL;
	execl(myargs[0], myargs[0], myargs[1]);
}

/* Not allowed on this architecture... :(
void ls_execvpe()
{
	printf("using execvpe\n");
	char *myargs[2];
	myargs[0] = "/bin/ls";
	myargs[1] = NULL;
	execvpe(myargs[0], myargs, (char *)0);
}
*/

void ls_execle()
{
	printf("using execle\n");
	char *myargs[3];
	myargs[0] = "/bin/ls";
	myargs[1] = ".";
	myargs[2] = NULL;
	char *myenv[3];
	myenv[0] = "VAR=myvar";
	myenv[1] = NULL;
	execle(myargs[0], myargs[0], (char *)0, myenv);
}
