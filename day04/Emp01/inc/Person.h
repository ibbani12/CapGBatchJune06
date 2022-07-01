#pragma once

#include <string>
#include <cstring>
using namespace std;

class Person
{
protected:
	char Name[20];
	int age;
	char gender;
public:
	Person(){}
	Person(int a, const char* n, char g) { age = a; strcpy(Name,n); gender=g; }
	int getAge();
	char* getName();
	char getGender();
};
