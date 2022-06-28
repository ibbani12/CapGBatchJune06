#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/*


*/


int main()
{
	ofstream fio;
	//char line[100];
	string line;
	fio.open("test.txt", ios::out);
	if(!fio)
	{
		cout<<"Unable to open the input File"<<endl;
		exit(0);
	}

	cout<<"File opened Successfully"<<endl;

	getline(cin, line);
	//cin.getline(line, 10);
	fio<<line<<endl;
	
	fio.close();

	//read contents from the file
	ifstream fio1;
	//char line[100];
	string l2,l3;
	line="";
	fio1.open("test.txt", ios::in);
	if(!fio1)
	{
		cout<<"Unable to open the input File"<<endl;
		exit(0);
	}

	cout<<"File opened Successfully"<<endl;


	//fio1>>line;
	getline(fio1,line);

	cout<<line<<endl;
	
	fio1.close();



	return 0;

}