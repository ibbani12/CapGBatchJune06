#include <iostream>
#include <fstream>
#define MSGSIZE 16

using namespace std;

int main()
{
	fstream fs;
	char *msg1 = "Hello,World #1";
	char inbuf[MSGSIZE];
	int pd[2], pid;
	pipe(pd);
	pid = fork();
	if(pid > 0)
	{
		write(p[1], msg1, MSGSIZE);
	} 
	else
	{
		cout<<"\nChild process"<<endl;
		p[0].seekg(2, p[0].beg);
		int length = p[0].tellg();
		cout<<"length: "<<length<<endl;
	}
	
	// fs.open("test.txt", ios::in | ios ::out | ios::binary);
	// if(!fs)
	// {
	// 	cout<<"Open file error"<<endl;
	// 	exit(EXIT_FAILURE);
	// }
	// fs.seekg(0, fs.end);
 //    int length = fs.tellg();
 //    char * buffer = new char [length];
	// fs.seekg(2, fs.beg);
	// fs.read (buffer,length);
	// //cout<<buffer<<endl;
	// cout.write(buffer,length);

	// delete []buffer;

	return 0;
}