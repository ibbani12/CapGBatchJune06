#include <iostream>
#include <fstream>
#include <csignal>

using namespace std;

void func1();

int main()
{
	fstream fs;
	fs.open("Test.txt",ios::in | ios::out | ios::binary);
	if(!fs)
	{
		cout<<"Unable to open the file"<<endl;
		exit(0);
	}
	// fs <<"Hello World";
	fs.seekg(5,ios::beg);
	cout<<fs.tellg()<<endl;
	char buf[20];
	fs.read(buf,10);

	cout<<buf<<endl;
	fs.close();
	

	return 0;

}