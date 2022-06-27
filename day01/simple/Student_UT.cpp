
#include <cppunit/config/SourcePrefix.h>
#include <string>
#include<algorithm>

#include "Student_UT.h"

CPPUNIT_TEST_SUITE_REGISTRATION( Student );

bool isANum(const std::string &str)
{
	auto it = std::find_if(str.begin(), str.end(), [](const char &c) {
		return !isalnum(c);
	});

	return it==str.end();
}


void Student::setUp()
{
	name = "James123";
	rollno = 101;
}
void Student::getNameUT() {
		std::string Name = "Bhima";
		std::string Name2 = getName();
		
		CPPUNIT_ASSERT_EQUAL(true, isANum(getName()));
 }

	void Student::getRollNoUT(){
		CPPUNIT_ASSERT_EQUAL(101, getRollNo());
	}
