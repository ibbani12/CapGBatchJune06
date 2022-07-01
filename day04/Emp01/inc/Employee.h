#pragma once

#include <iostream>
#include <string>
#include <Person.h>
#include <cstring>

using namespace std;


class Employee : public Person
{
protected:
	char empid[10];
	char esid[10];
	int sal;
	char role[10];
public:
	Employee(){}
	Employee(int a, const char* n, char g, const char* eid ) : Person(a,n,g){
		strcpy(empid, eid);
		strcpy(esid , "1001");
		sal = 0;
		strcpy(role , "SE");
	}

	Employee(int a, const char* n, char g, const char* eid, int s, const char* r, const char* sid) : Person(a,n,g){
		strcpy(empid, eid);
		strcpy(esid , sid);
		strcpy(role , r);
		sal = s;
	}
	void getEmpDetails();
	void display();
	char* getSid();
};
