#include <iostream>
#include <string>
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

#include "cbasicmath.h"



using namespace std;
using namespace CppUnit;

class TestBasicMath : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestBasicMath);
	CPPUNIT_TEST(testAddition);
	CPPUNIT_TEST(testMultiply);
	CPPUNIT_TEST_SUITE_END();

public:

	void setUp(void);
	void tearDown(void);

protected:
	void testAddition(void);
	void testMultiply(void);

private:

	CBasicMath *mTestObj;
};


void TestBasicMath::testAddition(void)
{
	CPPUNIT_ASSERT( 5 == mTestObj->Addition(2, 3));
}

void TestBasicMath::testMultiply(void)
{
	CPPUNIT_ASSERT( 6 == mTestObj->Multiply(2, 3));
}

void TestBasicMath::setUp(void)
{
	if ( !mTestObj ) 
		mTestObj = new CBasicMath();
}

void TestBasicMath::tearDown(void)
{
	if ( mTestObj )
	{
		delete mTestObj;
		mTestObj = 0;
	}
}


CPPUNIT_TEST_SUITE_REGISTRATION( TestBasicMath );

int main(int argc, char *argv[])
{
	CPPUNIT_NS::TestResult testresult;

	CPPUNIT_NS::TestResultCollector collectedresults;

	testresult.addListener(&collectedresults);


	CPPUNIT_NS::BriefTestProgressListener progress;
	testresult.addListener(&progress);


	CPPUNIT_NS::TestRunner testrunner;

	testrunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
	testrunner.run(testresult);

	CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
	compileroutputter.write();


	ofstream xmlFileOut("cppTestBasicMathResults.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();

	return collectedresults.wasSuccessful() ? 0 : 1;
}

