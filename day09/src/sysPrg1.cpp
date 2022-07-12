#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

using namespace std;


int main()
{
	int pid;//, *i=new int;
	int i=0;

	// for(;;)
	// {
	// 	pid = fork();
	// 	if(pid < 0)
	// 	{
	// 		cout<<"Maximum of concurrent processes are "<<i<<endl;
	// 	}
	// 	if(pid == 0)
	// 	{
	// 		i++;
	// 	}
	// 	else
	// 	{
	// 		wait(0);
	// 		exit(0);
	// 	}

	// }
	i = 10;
	pid = fork();
	if(pid == 0)
	{
		cout<<"Address of I (child process)";
		printf("%u and its value = %d\n",&i, i);
		cout<<"\nInitial value of i = "<<i<<endl;
		i+=25;
		cout<<"\nValue after i changed = "<<i<<endl;
		
		cout<<"\nChild terminates"<<endl;
	}
	else{
		wait(0);
		cout<<"Address of I (Parent process)";
		printf("%u and its value = %d\n",&i,i);
		cout<<"\nI value after child process(in Parent) "<<i<<endl;
	}


	

	return 0;
}