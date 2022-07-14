#include <iostream>
#include <csignal>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;
int pid,i;

static void func1(int id)
{
	cout<<"\n i = "<<i<<endl;
	cout<<"Child Died"<<endl;
	wait(NULL);
	cout<<"ID: "<<id<<endl;
	
	
}


int main()
{
	signal(SIGCHLD, func1);
	pid = fork();
	if(pid == 0)
	{
		sleep(1);
		cout<<"Child"<<endl;
		
	}	
	else
	{	
		
		
		int ret;
		wait(0);
		cout<<"Parent"<<endl;
		for(int i=0;i<10000;i++);
			
		cout<<"\nParent Dies"<<endl;
	}

	return 0;
}

