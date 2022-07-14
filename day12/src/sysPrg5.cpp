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
	cout<<"ID: "<<id<<endl;
	getchar();
}


int main()
{
	pid = fork();
	if(pid == 0)
	{
		//sleep(1);
		cout<<"Child"<<endl;
		
	}	
	else
	{	
		cout<<"Parent"<<endl;
		sleep(50);
		
		signal(SIGCHLD, func1);
		for(int i=0;i<10000;i++)
			cout<<"i: "<<i<<" ";
		cout<<"\nParent Dies"<<endl;
	}

	return 0;
}

