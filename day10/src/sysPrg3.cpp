#include <myheader.h>

int main(int argc, char *argv[], char*envp[])
{
	for(int i=0;i<argc;i++)
	 	cout<<"argv["<<i<<"] = "<<argv[i]<<endl;
	 cout<<"\n=========================\n";
	 for(int i=0;envp[i];i++)
	 	cout<<"envp["<<i<<"] = "<<envp[i]<<endl;

	return 0;
}