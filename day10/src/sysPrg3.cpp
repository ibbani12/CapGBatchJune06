#include <myheader.h>

extern char **environ;

// int main(int argc, char *argv[], char*envp[])
// {
// 	for(int i=0;i<argc;i++)
// 	 	cout<<"argv["<<i<<"] = "<<argv[i]<<endl;
// 	 cout<<"\n=========================\n";
// 	 for(int i=0;envp[i];i++)
// 	 	cout<<"envp["<<i<<"] = "<<envp[i]<<endl;

// 	return 0;
// }

int main()
{
		 for(int i=0;environ[i];i++)
		 	cout<<"envp["<<i<<"] = "<<environ[i]<<endl;

		 return 0;

}