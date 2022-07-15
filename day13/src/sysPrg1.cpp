/*
prototype

void (signal (int sig, void(*func)(int)))(int);

int raise(int sig);

raise => sends signal to the process/program
0 = success
non zero = failure

*/


#include <iostream>
#include <csignal>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

sig_atomic_t signalled = 0;

void handler(int signum)
{
	signalled = 1;
}

int main(int argc, char *argv[])
{
	signal(SIGINT, handler);
	int sigNum = atoi(argv[1]);
	cout<<"Before signal is called"<<endl;
	cout<<"signal = "<<signalled<<endl;
	raise(sigNum);
	cout<<"After signal is called"<<endl;
	cout<<"signal = "<<signalled<<endl;
	

	return 0;
}