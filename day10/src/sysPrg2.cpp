#include <myheader.h>

int main(int argc, char *argv[])
{
	char* temp[3];
	temp[0]= argv[1];
	temp[1]= argv[2];
	//temp[2]= (char*)0;
	cout<<"\nBefore exec sys call PID: "<<getpid()<<endl;
	cout<<"\nParent PID: "<<getppid()<<endl;
	cout<<"\nExec starts"<<endl;
	execv("/home/bhima/CapGJune6/CapGBatchJune06/day10/hello",argv);
	cout<<"\nThis will not print"<<endl;

	return 0;
}