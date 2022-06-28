#pragma once

#include <iostream>
#include <string>
#include <Person.h>

using namespace std;


class Employee : public Person
{
protected:
	string empid;
	string esid;
	int sal;
	string role;
public:
	Employee(){}
	Employee(int a, string n, char g, string eid ) : Person(a,n,g){
		empid = eid;
		esid = "1001";
		sal = 0;
		role = "SE";
	}

	Employee(int a, string n, char g, string eid, int s, string r, string sid) : Person(a,n,g){
		empid = eid;
		esid = sid;
		sal = s;
		role = r;
	}
	void display();
	string getSid();
};
