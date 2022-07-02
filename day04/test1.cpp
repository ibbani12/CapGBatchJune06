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
	void setEmp(int i, string n, int s)
	{
		id = i; 
		name=n; 
		sal=s; 
	}
protected:
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
	Manager(int i, string n, int s, string r) : Employee(i,n,s) { role = r; }
	string getRole(){ return role; }
	void setRole(string r){ role = r; }
	void setValues(int i, string n, int s, string r)
	{
		setEmp(i,n,s);
		role = r;
	}

	void dispManager()
	{
		cout<<"\nName: "<<getName();
		cout<<"\nID: "<<"EMP_"<<getID();
		cout<<"\nSalary: "<<getSal(); 
		cout<<"\nRole: "<<role<<endl;
	}

};


int main()
{
	
	//Manager M(101, "rahul", 10000,"Director");
	//M.dispEmp();
	Manager *M = new Manager[3];
	M[0].dispManager();
	M[1].dispManager();
	M[2].dispManager();
	M[1].setValues(101, "rahul", 10000,"Director");
	M[1].dispManager();



	return 0;
}