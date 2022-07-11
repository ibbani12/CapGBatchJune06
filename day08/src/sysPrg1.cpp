#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
	int c=0, p=0, pid;
	pid = fork();
	if(pid == 0)
	{

		cout<<"\nChild Starts"<<endl;
		
		for(c=0;c<1000;c++)
			cout<<"c="<<c<<endl;
		cout<<"\nChild Ends"<<endl;
	}
	else
	{
		cout<<"\nParent Starts"<<endl;
		if(pid>0){
			wait(0);
			for(p=0;p<1000;p++)
				cout<<"p="<<p<<endl;
		}
		cout<<"\nParent Ends"<<endl;

	}	

	return 0;
}