#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int a=stoi(argv[1]);

	//char a = argv[1][0];

	switch(a)
	{
	case 98:
		cout<<"10"<<endl;
		break;
	case 'a':
		cout<<"20"<<endl;
		break;
	case 'b':
		cout<<"30"<<endl;
		break;
	case 'd':
		cout<<"40"<<endl;
		break;
	default:
		cout<<"default got executed/ not in the list"<<endl;
		break;
	
	}

	return 0;
}



