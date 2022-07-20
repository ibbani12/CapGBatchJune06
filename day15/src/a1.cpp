#include <myheader.h>
#define MAXBUFF 1024

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cout<<"Useage: ./app input.txt"<<endl;
		exit(EXIT_FAILURE);
	}
	char *fName = argv[1];

	fstream fs;
	fs.open(fName, ios::out);
	if(!fs)
	{
		cout<<"Unable to open the input file(Writing)"<<endl;
		exit(EXIT_FAILURE);
	}

	for(int i=0;i<2;i++)
	{
		string line;
		getline(cin, line);
		fs<<line<<endl;
	}
	fs.close();

	fs.open(fName, ios::in);
	if(!fs)
	{
		cout<<"Unable to open the input file(Reading)"<<endl;
		exit(EXIT_FAILURE);
	}

	string line1;
	while(getline(fs, line1))
		cout<<line1<<endl;
	

	return 0;

}
