#include <iostream>


using namespace std;

class Student
{
protected:
	int rollno;
	string name;
public:
	Student(){}
	Student(int r, string n) { rollno =r; name = n; }
	string getName() { return name; }
	int getRollNo() { return rollno; }

};