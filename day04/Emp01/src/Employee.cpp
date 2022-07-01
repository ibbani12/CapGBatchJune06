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

char* Employee::getSid(){ return esid; }

void Employee::setSal(int s) { sal = s;}

void Employee::getEmpDetails()
{
	cout<<"\nEnter Employee Details"<<endl;
	cout<<"\nE Name: ";
	cin>>Name;
	cout<<"\nAge: ";
	cin>>age;
	cout<<"\nGender: ";
	cin>>gender;
	cout<<"\nEmp ID: ";
	cin>>empid;
	cout<<"\nSupervisor ID: ";
	cin>>esid;
	cout<<"\nSalary: ";
	cin>>sal;
	cout<<"\nRole: ";
	cin>>role;

}