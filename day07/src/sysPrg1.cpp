#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main()
{
	int pid;
	pid = fork();
	if(pid==0){
		sleep(15);
		cout<<"I am a child, my process pid : "<<getpid()<<endl;
		cout<<"I am Child, my Parent PID : "<<getppid()<<endl;


	}
	else
	{
		cout<<"I am a Parent, my process pid : "<<getpid()<<endl;
		cout<<"I am Parent, my Parent PID : "<<getppid()<<endl;
		

	}
	return 0;
}