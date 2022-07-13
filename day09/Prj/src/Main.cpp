#include <Student.h>
#include <iostream>

using namespace std;

int main()
{
	Student *s = new Student;
	s->dispStudent();

	delete []s;
	return 0;
}