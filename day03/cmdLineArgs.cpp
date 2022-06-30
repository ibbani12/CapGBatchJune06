#include<iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class Employee 
{
protected:
	string empid;
	string name;
	int sal;
	string role;
public:
	Employee(){}
	Employee(int a, string n, string r, string eid ) {
		empid = eid;
		name = n;
		sal = a;
		role = r;
	}

	
	void display(){
		cout<<"name: "<<name<<endl;
		cout<<"salary: "<<sal<<endl;
	}
	string getSid();
};


int main(int argc, char *argv[])
{

	string buf;
	cout<<"\nNo of args passed to the program: "<<argc<<endl;
	for(int i=0;i<argc;i++)
	{
		cout<<"argv["<<i<<"] = "<<argv[i]<<endl;
	}

	Employee e(stoi(argv[1]),argv[2], argv[3],argv[4]);

	e.display();

	// fstream f1;
	// f1.open(argv[1], ios::in);

	// if(!f1)
	// {
	// 	cout<<"unable to open the file"<<endl;
	// 	exit(0);
	// }

	// while(!f1.eof())
	// {
	// 	getline(f1, buf);
	// 	cout<<buf<<endl;
	// }

	return 0;
}