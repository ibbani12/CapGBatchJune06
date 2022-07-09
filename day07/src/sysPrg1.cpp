#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main()
{
	int pid;
	pid = fork();
	if(pid>0){
		cout<<"Hello World!"<<endl;
		cout<<"PID: "<<getpid()<<endl;
		cout<<"PPID: "<<getppid()<<endl;
		sleep(10);
	}
	return 0;
}