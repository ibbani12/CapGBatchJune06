#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int pd[2], n, i;
char line[256];
int main()
{
	pipe(pd); // create a pipe
	printf("pd=[%d, %d]\n", pd[0], pd[1]);
	if (fork()){ // fork a child to share the pipe
		
		printf("parent %d close pd[0]\n", getpid());
		close(pd[0]); // parent as pipe WRITER
		while(i++ < 10){ // parent writes to pipe 10 times
			printf("parent %d writing to pipe\n", getpid());
			n = write(pd[1], "I AM YOUR PAPA", 16);
			printf("parent %d wrote %d bytes to pipe\n", getpid(), n);
			sleep(5);
		}
		printf("parent %d exit\n", getpid());
	}
	else{

		printf("child %d close pd[1]\n", getpid());
		close(pd[1]); // child as pipe READER
		while(1){ // child read from pipe
			printf("child %d reading from pipe\n", getpid());
			if ((n = read(pd[0], line, 128))){ // try to read 128 bytes
				line[n]=0;
				printf("child read %d bytes from pipe: %s\n", n, line);
			}
			else // pipe has no data and no writer
				exit(0);
		}
	}
}