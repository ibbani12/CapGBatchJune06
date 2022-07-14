#include <iostream>
#include <fstream>
#include <csignal>

using namespace std;

void func1();

int main()
{
	fstream fs;
	fs.open("Test.txt",ios::in | ios::binary);
	if(!fs)
	{
		cout<<"Unable to open the file"<<endl;
		exit(0);
	}
	fs.seekg(50,ios::beg);
	cout<<fs.tellg()<<endl;

	return 0;

}