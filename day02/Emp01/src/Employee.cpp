#include <Employee.h>

void Employee::display()
{
		cout<<"\nEmployee Details"<<endl;
		cout<<"\nName: "<<getName();
		cout<<"\nAge: "<<age;
		cout<<"\nGender: "<<gender;
		cout<<"\nEmployee ID: "<<empid;
		cout<<"\nSalary: "<<sal;
		cout<<"\nRole: "<<role;
		cout<<"\nSID: "<<esid;
		cout<<"\n\n";
}

string Employee::getSid(){ return esid; }