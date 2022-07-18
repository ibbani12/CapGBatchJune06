#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream fs;
	
	
	fs.open("test.txt", ios::in | ios ::out | ios::binary);
	if(!fs)
	{
		cout<<"Open file error"<<endl;
		exit(EXIT_FAILURE);
	}
	fs.seekg(0, fs.end);
    int length = fs.tellg();
    char * buffer = new char [length];
	fs.seekg(2, fs.beg);
	fs.read (buffer,length);
	//cout<<buffer<<endl;
	cout.write(buffer,length);

	delete []buffer;
}