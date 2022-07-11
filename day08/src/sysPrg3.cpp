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
		wait(0);
		dip = fork();
		if(dip == 0)
		{
			cout<<"2nd child's PID: "<<getpid()<<endl;
			cout<<"2nd Parent's PID: "<<getppid()<<endl;
			cout<<"2nd child process dead"<<endl;
		}
		else
		{
			wait(0);
			cout<<"2nd Parent PID: "<<getpid()<<endl;
			cout<<"2nd Parent's PPID : "<<getppid()<<endl;

		}
		
		cout<<"Parent PID: "<<getpid()<<endl;
		cout<<"Parent's PPID : "<<getppid()<<endl;

	}

	return 0;
}

/*
ouput

1st child's PID: 8247
1st Parent's PID: 8246
1st child process dead
2nd child's PID: 8248
2nd Parent's PID: 8246
2nd child process dead
Parent PID: 8246
Parent's PPID : 4311

*/