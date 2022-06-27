#pragma once

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
	int getAge();
	string getName();
	char getGender();
};
