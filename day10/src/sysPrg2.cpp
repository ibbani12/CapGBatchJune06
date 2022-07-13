#include <myheader.h>

int main()
{
	cout<<"\nBefore exec sys call PID: "<<getpid()<<endl;
	cout<<"\nParent PID: "<<getppid()<<endl;
	cout<<"\nExec starts"<<endl;
	execl("/home/bhima/CapGJune6/CapGBatchJune06/day10/hello", "hello",(char *)0);
	cout<<"\nThis will not print"<<endl;

	return 0;
}