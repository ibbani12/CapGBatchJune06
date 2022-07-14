#include <iostream>
#include <csignal>

using namespace std;

static void signalHandler(int ID)
{
	cout<<"ID : "<<ID<<endl;
}

void RegisterSignal()
{
	signal(SIGINT, signalHandler);
	signal(SIGILL, signalHandler);
	signal(SIGFPE, signalHandler);
	signal(SIGSEGV, signalHandler);
	signal(SIGTERM, signalHandler);
	signal(SIGABRT, signalHandler);
	signal(SIGCHLD, signalHandler);
}


int main()
{
	RegisterSignal();
	for(;;);

	return 0;
}