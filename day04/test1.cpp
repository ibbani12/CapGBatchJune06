#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
	int id;
	string name;
	int sal;
public:
	Employee(){ id = 0; name="defaultName"; sal=0; }
	Employee(int i, string n, int s)
	{ 
		id = i; 
		name=n; 
		sal=s; 
	}
	int getID(){ return id; }
	string getName(){ return name; }
	int getSal(){ return sal; }

	void setSal(int x){ sal = x; }
	void setId(int i) { id = i; }
	void setName(string n){ name =n; }

	void dispEmp()
	{
		cout<<"\nName: "<<name;
		cout<<"\nID: "<<id;
		cout<<"\nSalary: "<<sal; 
	}

};

class Manager : public Employee
{
private:
	string role;
public:
	Manager(){ role = "Supervisor"; }
	Manager(string r) { role = r; }
	string getRole(){ return role; }
	void setRole(string r){ role = r; }

	void dispManager()
	{
		cout<<"\nRole: "<<role;
	}

};


int main()
{
	Employee E(101, "rahul", 10000);
	Manager M("Director");
	E.dispEmp();
	M.dispManager();



	return 0;
}