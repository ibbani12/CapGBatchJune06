#include <iostream>
#include<string>
#include <cstring>
#include <signal.h>

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fstream>

#include <time.h>


using namespace std;
void func2(int signum)
{
	cout<<"Interrupt: "<<signum<<endl;
	exit(0);
}

void func1()
{
	cout<<"Hello WOrld PID:"<<getpid()<<endl;
	
	kill(getpid(),SIGUSR1);
}

int main()
{
	signal(SIGCHLD,func2);
	
	if(fork()==0)
	{
		atexit(func1);
		for(;;);
	}
	else
	{
		atexit(func1);
		wait(0);
		cout<<"Hey1"<<endl;
		cout<<"Hey2"<<endl;
		cout<<"Hey3"<<endl;
		cout<<"Hey4"<<endl;
		sleep(20);

	}

	return 0;
}