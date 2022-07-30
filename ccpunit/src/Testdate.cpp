#include<iostream>
#include<string>
#include<thread>

using namespace std;
#include <bits/stdc++.h>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "Date.h"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class TestDate : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestDate);
  //todo :include the test functions for leap year and monthname i.e testcheckLeapYear(), testMonthName()
    CPPUNIT_TEST(testcheckLeapYear);
    CPPUNIT_TEST(testMonthName);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testcheckLeapYear(void);
    void testMonthName(void);

private:

    Date *mTestObj;
};

//-----------------------------------------------------------------------------
//todo Implement the below functions
void
TestDate::testcheckLeapYear(void)
{
   //todo add test code using ASSERT macro(s)
     CPPUNIT_ASSERT(true==2001);
}

void
TestDate::testMonthName(void)
{
   //todo add test code using ASSERT macro(s)
     CPPUNIT_ASSERT(month==1);
}

void TestDate::setUp(void)
{
    mTestObj = new Date(1,1,1969);
}

void TestDate::tearDown(void)
{
    delete mTestObj;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestDate );

int main(int argc, char*argv[])
{
    std::cout << "Have " << argc << " arguments:" << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
  
    if (argc != 3) {
    std::cout << "usage: tester name_of_class_being_test" <<endl;
    exit(1);
  }

    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // todo:register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (argc, argv[i]);

    

    // todo: insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;

   testrunner.addTest(argv[i],CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    testrunner.run(argc, argv[i]);

    // todo: output results in xml format
      CPPUNIT_NS::CompilerOutputter outputter(argc, argv[i]);
      outputter.write();


    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}