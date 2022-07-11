// Program to make parent wait for more than one child

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
	int pid, dip;
	
	pid = fork();
	if(pid ==0)
	{
		cout<<"1st child's PID: "<<getpid()<<endl;
		cout<<"1st Parent's PID: "<<getppid()<<endl;
		cout<<"1st child process dead"<<endl;
	}
	else
	{
		dip = fork();
		if(dip == 0)
		{
			cout<<"2nd child's PID: "<<getpid()<<endl;
			cout<<"2nd Parent's PID: "<<getppid()<<endl;
			cout<<"2nd child process dead"<<endl;
		}
		else
		{
			sleep(10);
			cout<<"2nd Parent PID: "<<getpid()<<endl;
			cout<<"2nd Parent's PPID : "<<getppid()<<endl;

		}
		sleep(5);

		cout<<"Parent PID: "<<getpid()<<endl;
		cout<<"Parent's PPID : "<<getppid()<<endl;

	}

	return 0;
}