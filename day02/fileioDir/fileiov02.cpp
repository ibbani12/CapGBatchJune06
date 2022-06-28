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

	return 0;

}