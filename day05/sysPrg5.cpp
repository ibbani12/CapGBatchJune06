#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main()
{

	int pid1 = fork();

	
	if(pid1 > 0)
		cout<<"\nPID1 using variable: "<<pid1<<endl;
	
	int pid2 = fork();
	
	if(pid2 > 0)
		cout<<"\nPID2 using variable: "<<pid2<<endl;
	
	cout<<"PID : "<<getpid()<<endl;
	cout<<"PPID : "<<getppid()<<endl;
	cout<<endl;
	sleep(10);
	return 0;
}