#include <iostream>
#include <csignal>

using namespace std;

void func1(int);

int main()
{
	cout<<"\nPress CTRL + C key\n"<<endl;
	signal(SIGINT, func1);
	for(;;);

	return 0;
}

void func1(int sigNum)
{
	cout<<"Interrupt signal ("<<sigNum<<") received"<<endl;
	exit(sigNum);
}