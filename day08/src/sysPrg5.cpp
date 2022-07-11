#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
	// int i,j=0;
	// i = 10/j;
	// cout<<i;
	// return 0;

	int i,pid,status, j=0;
	pid = fork();
	if(pid == 0){
		i = 10/j;
		cout<<i<<endl;
	}
	else
	{
		wait(&status);
		if(status & 0x80)
			cout<<"Floating point exception (core dumped)"<<endl;
		else
			cout<<"No exception occured!"<<endl;
	}

	return 0;
}