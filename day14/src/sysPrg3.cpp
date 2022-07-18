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
		close(fd[1]);
		
		n = read(fd[0], line, BUFF);
		cout<<"Printing in parent"<<endl;
		write(STDOUT_FILENO, line, n);
		cout<<endl;
	}
	else   //child process
	{
		close(fd[0]);
		//write(fd[1], "Hello from Child", 16);
		
	}

	return 0;
}