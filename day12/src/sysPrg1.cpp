#include <iostream>
#include <signal.h>

using namespace std;

void* func1();

int main()
{
	cout<<"\nPress <DEL> key\n"<<endl;
	signal(SIGINT, func1);
	for(;;);

	return 0;
}


void* func1()
{
	cout<<"Hey Bhima!\nYou have pressed the <DEL> key"<<endl;
	return ((void *)0);
}