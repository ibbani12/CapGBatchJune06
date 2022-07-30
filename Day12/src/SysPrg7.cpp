#include <iostream>
#include <csignal>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

void func1(int);

int pid;

int main()
{
	signal(SIGUSR1, func1);
	pid = fork();
	if(pid ==0)
	{
		cout<<"CHILD PID: "<<pid<<endl;
		cout<<"PPID: "<<getppid()<<endl;
		sleep(25);
		//kill(getppid(),SIGUSR1);
		exit(0);
	}
	else
	{
		
		cout<<"PID : "<<pid<<endl;
		sleep(20);
		cout<<"getpid: "<<getpid()<<endl;
		kill(getppid(),SIGUSR1);
		for(int i=0;i<1000;i++)
			cout<<"i="<<i<<" ";
		cout<<endl;	
		cout<<"\nParent exiting"<<endl;
	}
}

void func1(int id)
{
	cout<<"Signal is received by the child"<<endl;
	cout<<"Child Died"<<endl;
	cout<<"ID: "<<id<<endl;
}