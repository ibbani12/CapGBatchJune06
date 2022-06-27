#ifndef CPP_UNIT_EXAMPLETESTCASE_H
#define CPP_UNIT_EXAMPLETESTCASE_H

#include <cppunit/extensions/HelperMacros.h>
#include <string>

/* 
 * A test case that is designed to produce
 * example errors and failures
 *
 */

class ExampleTestCase : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( ExampleTestCase );
  CPPUNIT_TEST( example );
  CPPUNIT_TEST( anotherExample );
  CPPUNIT_TEST( testAdd );
  CPPUNIT_TEST( testEquals );
  CPPUNIT_TEST_SUITE_END();

protected:
  double m_value1;
  double m_value2;

public:
  void setUp();

protected:
  void example();
  void anotherExample();
  void testAdd();
  void testEquals();
  int t1()
  {
    return 12;
  }

  std::string t2()
  {
    return "James";
  }

};


#endif
