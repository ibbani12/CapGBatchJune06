#include <iostream>
#include <signal.h>
#include <cstring>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fstream>
#include <string>
#include <time.h>

#define MAXBUFF 1024

using namespace std;


static void func1(int signum)
{
	//cout<<"Sig Number: "<<signum<<endl;
	switch(signum)
	{
		case SIGSEGV:
			cout<<"Sig Number: "<<signum<<endl;
			cout<<"Seg fault error occured"<<endl;
			exit(EXIT_FAILURE);
			break;

		case SIGUSR1:
			cout<<"Welcome User!"<<endl;
			break;

		case SIGHUP:
			cout<<"SIGNAL HANG UP occured! : "<<signum<<endl;
			break;

		case SIGCHLD:
			cout<<"SIGNAL CHILD occured! : "<<signum<<endl;
			break;

		default:
			cout<<"\nUnhandled signal : "<<signum<<endl;

	}
	
}

int main()
{
	sighandler_t ret = signal(SIGUSR1,func1);
	

	if(ret == SIG_ERR)
	{
		perror("signal() error");
		exit(EXIT_FAILURE);
	}
	int pid = fork();
	int status;
	if(pid == 0)
	{
		cout<<"Child's Process=> PID: "<<getpid()<<endl;
		cout<<"Child's Parent ID: "<<getppid()<<endl;
		for(;;);
	}
	else
	{
		signal(SIGCHLD,func1);

		waitpid(pid, &status, 0);

		cout<<"Parent PID: "<<getpid()<<endl;
		cout<<"Parent's Parent ID: "<<getppid()<<endl;
		cout<<"Status: "<<status<<endl;
	}

	return (EXIT_SUCCESS);
}