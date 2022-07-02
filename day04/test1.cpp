#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Employee
{
protected:
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
	Manager(const Manager &obj){
		// cout<<"\nCopy Construtor is called"<<endl;
		// cout<<"\nCopy Cons Name: "<<obj.role;
		// cout<<"\nCopy Cons ID: "<<obj.id;
		this->id = obj.id+1;
		this->name = "defaultName";
		//this->role = obj.role ;
		//this->sal = obj.sal+10001;

	}

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

	void operator=(const Manager &obj){
		this->id = obj.id+1;
		
	}

};


int main()
{
	
	Manager M1(101, "rahul", 10000,"Director");
	M1.dispManager();

	//Manager M2 = M1;
	// //M2.dispManager();
	// //M2.setValues(102, "rahul1", 10000,"Director1");
	// Manager M3 = M2;
	// Manager M4 = M3;
	// M2.dispManager();
	// M3.dispManager();
	// M4.dispManager();

	Manager *M = new Manager[5];
	M[0] = M1;
	for(int i=1;i<5;i++)
	{
		M[i] = M[i-1];
	}

	for(int i=0;i<5;i++)
	{
		M[i].dispManager();
	}
	// Manager *M = new Manager[3];
	// M[0].dispManager();
	// M[1].dispManager();
	// M[2].dispManager();
	// M[1].setValues(101, "rahul", 10000,"Director");
	// M[1].dispManager();



	return 0;
}