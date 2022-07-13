#include <myheader.h>

int main(int argc, char *argv[])
{
	cout<<"Hello!, Good Day"<<endl;
	cout<<"Hello PID: "<<getpid()<<endl;
	cout<<"Hello PPID: "<<getppid()<<endl;
	for(int i=0;i<argc;i++)
	 	cout<<"argv["<<i<<"] = "<<argv[i]<<endl;

	cout<<"Exec ends"<<endl;
	return 0;
}