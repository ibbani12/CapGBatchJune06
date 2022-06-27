#pragma once
#include <iostream>
#include <cppunit/extensions/HelperMacros.h>


using namespace std;



class Student : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( Student );
  CPPUNIT_TEST( getNameUT );
  CPPUNIT_TEST( getRollNoUT );
  CPPUNIT_TEST_SUITE_END();

protected:
	int rollno;
	string name;
	
public:
    void setUp();
	string getName() { return name; }
	int getRollNo() { return rollno; }
	
protected:
	void getNameUT();
	void getRollNoUT();
};