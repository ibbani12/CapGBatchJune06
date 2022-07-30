#include <iostream>
#include <cstring>

using namespace std;

void f(char *name)
{
	
	
	size_t s = sizeof(name);
	cout<<"In FUnction: "<<s<<endl;
	strcpy(name,"bhima");
	
}

int main()
{
	char *name  = NULL; 
	name = new char[20];
	size_t s = sizeof(name);
	cout<<"Before: "<<s<<endl;
	f(name);
	s = sizeof(name);
	cout<<"After: "<<s<<endl;

	//cout<<f(name)<<endl;
	cout<<name<<endl;
	return 0;
}