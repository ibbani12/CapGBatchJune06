/*
creating a child process - using fork
*/

#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main()
{
	static int count=0;
	cout<<"Hello WOrld! Parent"<<endl;
	fork();
	cout<<"Address of count = "<<&count<<endl;
	for(;;){
		if(count >= 5)
			break;
		cout<<"Hello WOrld! Child count="<<++count<<endl;
	}

	return 0;
}