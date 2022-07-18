#include <sysPrg.h>
#define BUFF 20

//int BUFF_SIZE 20;

int main()
{
	int n,fd[2];
	pid_t pid;

	char line[BUFF];

	if(pipe(fd) < 0)
		perror("pipe");
	if((pid = fork())< 0)
		perror("fork");
	else if(pid > 0)   //parent process
	{
		close(fd[0]);
		sleep(20);
		write(fd[1], "Hello World\n", 12);
	}
	else   //child process
	{
		close(fd[1]);
		sleep(50);
		n = read(fd[0], line, 20);
		write(STDOUT_FILENO, line, n);
	}

	return 0;
}