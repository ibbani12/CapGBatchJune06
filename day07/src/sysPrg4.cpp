#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


using namespace std;

int main()
{
	int i=0, j=0, pid;
	pid = fork();
	if(pid == 0)
	{
		for(i=0;i<1000;i++)
			cout<<"i="<<i<<endl;
	}
	else
	{
		if(pid>0){
			wait(0); // Process Sync
			for(j=0;j<1000;j++)
				cout<<"j="<<j<<endl;
		}
	}

	return 0;
}