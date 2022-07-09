#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main()
{
	if(fork() > 0)
	{
		cout<<"\nIam Parent"<<endl;
		sleep(50);
	}
	
	return 0;
}