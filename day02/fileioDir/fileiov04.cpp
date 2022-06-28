#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
/*


*/


int main()
{
	ifstream fio;
	char line[100];
	int a;
	float b;
	char c;
	fio.open("test.txt", ios::in);
	if(!fio)
	{
		cout<<"Unable to open the input File"<<endl;
		exit(0);
	}

	cout<<"File opened Successfully"<<endl;
	
	while(!fio.eof()){
		strcpy(line, "");
		a=0;
		b=0.0;
		c=0;
		fio>>line>>a>>b>>c;

		cout<<line<<endl;
		cout<<(a+10)<<endl;
		cout<<(b+30.05f)<<endl;
		cout<<c<<endl;
	}

	// fio>>line>>a>>b>>c;

	// cout<<line<<endl;
	// cout<<(a+10)<<endl;
	// cout<<(b+30.05f)<<endl;
	// cout<<c<<endl;


	// fio>>line>>a>>b>>c;

	// cout<<line<<endl;
	// cout<<(a+10)<<endl;
	// cout<<(b+30.05f)<<endl;
	// cout<<c<<endl;



	fio.close();

	return 0;

}