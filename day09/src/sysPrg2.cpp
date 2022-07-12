#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#define BUF_SIZE 2000
using namespace std;


int main(int argc, char *argv[])
{
	fstream f;
	char chr[] = "Rahul Dravid";
	//char *chr1;
	char buf[BUF_SIZE];
	int pid;
	pid = fork();
	if(pid == 0)
	{
		cout<<"Child Starts"<<endl;

		f.open(argv[1], ios::out);
	
		if(!f)
		{
			cout<<"\nUnable to open the file"<<endl;
			exit(0);
		}

		f.write(reinterpret_cast<char *>(&chr),sizeof(chr));

		f.close();
		cout<<"Child terminates"<<endl;

	}
	else
	{
		wait((int *)0);
		cout<<"Parent Starts"<<endl;

		f.open(argv[1], ios::in);
	
		if(!f)
		{
			cout<<"\nUnable to open the file"<<endl;
			exit(0);
		}

		cout<<"Sizeof buf : "<<sizeof(buf)<<endl;
		f.read(reinterpret_cast<char*>(&buf),sizeof(buf));
		cout<<"\nRead characters from the file "<<buf<<endl;
		f.close();
		cout<<"Parent terminates"<<endl;
	}

	


	return 0;
}