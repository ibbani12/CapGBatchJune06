#include <iostream>
#include "Student.h"

int main()
{
	Student S(101,"James");
	std::cout<<S.getRollNo()<<" "<<S.getName()<<std::endl;
	
	return 0;
}