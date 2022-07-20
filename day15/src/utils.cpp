#include <myheader.h>

void Write2File(char *fName)
{
	string line;

	fstream fs;
	fs.open(fName, ios::out);
	if(!fs)
	{
		cout<<"Unable to open the input file(Writing)"<<endl;
		exit(EXIT_FAILURE);
	}

	for(int i=0;i<2;i++)
	{
		
		getline(cin, line);
		fs<<line<<endl;
	}
	fs.close();

}

void ReadFromFile(char *fName)
{
	string line;

	fstream fs;

	fs.open(fName, ios::in);
	if(!fs)
	{
		cout<<"Unable to open the input file(Reading)"<<endl;
		exit(EXIT_FAILURE);
	}

	line ="";
	while(getline(fs, line)){
		cout<<line<<endl;
		line="";
	}

	fs.close();
}

