#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void func1();

int main()
{
	int fd;
	signal(SIGSYS, func1);
	fd = open("Test.txt", O_RDONLY);
	lseek(fd, 0L, 5);

	return 0;
}

void func1()
{
	printf("\nIllegal use of system call\n");
	exit(0);
}