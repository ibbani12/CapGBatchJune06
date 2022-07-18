#include <stdio.h>
#include <fcntl.h>
#define MSGSIZE 1024

int main()
{
	int fd;
	char msg[1024];
	// fd = open("test.txt", O_RDONLY);
	// lseek(fd, 2L,0);
	// read(fd,msg,1024);
	// printf("\nMsg: \n%s",msg);

	// close(fd);


	char *msg1 = "Hello,World #1";
	char inbuf[MSGSIZE];
	int pd[2], pid;
	int length=0;
	pipe(pd);
	pid = fork();
	if(pid > 0)
	{
		write(pd[1], msg1, MSGSIZE);
	} 
	else
	{
		printf("\nChild process\n");
		length = lseek(pd[0],2L,0);
		printf("\nLength: %d",length);
		read(pd[0],inbuf,MSGSIZE);
		printf("\nBuf: \n%s",inbuf);
		
		
	}



	return 0;
}