#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
	int pid, exitstat, status;
	int i;
	pid = fork();
	if(pid == 0)
	{
		cout<<"Enter the exit status: ";
		cin>>i;
		exit(i);
	}
	else
	{
		wait(&status);

		if((status & 0xff) != 0)
			cout<<"\nSignal interrupted!"<<endl;
		else
		{
			exitstat = (int) status/256;
			cout<<"\nExit Status from "<<pid<<" was = "<<exitstat<<endl;
			
		}

	}

	return 0;
}