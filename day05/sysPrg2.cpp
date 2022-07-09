/*
	ps -ef or ps => pid of the process
	wap to get the pid of the process
*/
#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main()
{
	int pid;
	int ppid;
	pid = getpid();
	ppid = getppid();

	cout<<"\nProcess ID of this is : "<<pid<<endl;
	cout<<"\nParent Process ID of this is : "<<ppid<<endl;
	sleep(10);

	return 0;
}