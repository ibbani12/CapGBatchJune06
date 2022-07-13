#include <myheader.h>
#define PATH "/home/bhima/CapGJune6/CapGBatchJune06/day10/"
#define FILEPATH "data/book.dat"


int main()
{
	fstream fs;
	char buf[11];
	int pid, i;
	string fpath = PATH;
	fpath += FILEPATH;
	
	fs.open(fpath,ios::in | ios::out);
	if(!fs)
	{
		cout<<"Unable to create/open the file"<<endl;
		exit(0);
	}
	for(i = 0;i<1024;++i)
		fs<<"A";
	for(i = 0;i<1024;++i)
		fs<<"B";
	for(i = 0;i<1024;++i)
		fs<<"C";
	for(i = 0;i<1024;++i)
		fs<<"D";
	fs.close();

	fs.open(fpath, ios::in);
	if(!fs)
	{
		cout<<"Unable to create/open the file"<<endl;
		exit(0);
	}

	pid = fork();

	if(pid == 0)
	{
		while(fs.read(buf, sizeof(buf))){
			cout<<"Read Buffer: \n"<<buf<<endl;
			cout<<"File pointer is at Pos: "<<fs.tellg()<<endl;
		}

	}
	else{
		wait((int *)0);
	}

	fs.close();

	return 0;
}