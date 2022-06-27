#pragma once

#include <iostream>
#include <string>
#include <Person.h>

using namespace std;


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
	void display();
};
