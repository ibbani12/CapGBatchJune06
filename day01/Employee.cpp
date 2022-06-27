#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
	string Name;
	int age;
	char gender;
public:
	Person(){}
	Person(int a, string n, char g) { age = a; Name=n; gender=g; }
	int getAge() { return ag; }
	string getName() { return Name; }
	char getGender() { return gender; }
};

class Employee : public Person
{
protected:
	string empid;
	int sal;
	string role;
public:
	Employee(){}
	Employee(int a, string n, char g, string eid, int s, string r) : Person(a,n,g){
		empid = eid;
		sal = s;
		role = r;
	}
	void display()
	{
		cout<<"\nEmployee Details"<<endl;
		cout<<"\nName: "<<Name;
		cout<<"\nAge: "<<age;
		cout<<"\nGender: "<<gender;
		cout<<"\nEmployee ID: "<<empid;
		cout<<"\nSalary: "<<sal;
		cout<<"\nRole: "<<role;
	}
};


int main()
{
	Employee E(30, "James", 'M', "CG_001",30000,"SE");

	E.display();

	return 0;

}