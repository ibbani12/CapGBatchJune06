#include <iostream>
#include <fstream>

using namespace std;
/*


*/


int main()
{
	ifstream fio;
	string line;
	fio.open("test.txt", ios::in);
	if(!fio)
	{
		cout<<"Unable to open the input File"<<endl;
		exit(0);
	}

	cout<<"File opened Successfully"<<endl;
	while(!fio.eof())
	{
		line="";
		getline(fio, line);
		cout<<line<<endl;
	}

	fio.close();

	return 0;

}