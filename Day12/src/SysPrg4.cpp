#include <iostream>
#include <cstring>
#include <csignal>

using namespace std;
static void signalHandler(int ID)
{
	cout<<"ID : "<<ID<<endl;
	if(ID == 11)
	{
		cout<<"Seg core dump"<<endl;
		exit(0);
	}
}

int main()
{

	char* buf;// = new char[20];
	signal(SIGSEGV, signalHandler);
	strcpy(buf,"Bhima");
	cout<<"Bye"<<endl;
	return 0;
}