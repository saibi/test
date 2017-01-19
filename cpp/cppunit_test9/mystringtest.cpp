#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestListener.h>
#include <cppunit/TestResult.h>

#include "mystring.h"

#include <iostream>


class mystringTest:public CppUnit::TestFixture
{
public:
	void setUp()
	{
		std::cout << "setUp code\n";
	}

	void tearDown()
	{
		std::cout << "clean code\n";
	}


	void checkLength()
	{
		mystring s;
		std::cout << "run checkLength\n";
		CPPUNIT_ASSERT_MESSAGE("String Length Non-Zero", s.size() == 0);
	}

	void checkValue()
	{
		mystring s;
		std::cout << "run checkValue\n";
		s.setbuffer("hello world!\n");
		CPPUNIT_ASSERT_EQUAL_MESSAGE("Corrupt String Data", 'w', s[0]);
	}

	CPPUNIT_TEST_SUITE( mystringTest );
	CPPUNIT_TEST( checkLength );
	CPPUNIT_TEST( checkValue );
	CPPUNIT_TEST_SUITE_END();
};

class mystringTest2: public mystringTest
{
public:
	void checkTwo()
	{
		mystring s;
		s.setbuffer("ok");
		CPPUNIT_ASSERT_EQUAL_MESSAGE("Corrupt String Data", 'o', s[1]);
	}

	CPPUNIT_TEST_SUB_SUITE(mystringTest2, mystringTest);
	CPPUNIT_TEST( checkTwo );
	CPPUNIT_TEST_SUITE_END();
};

class myListener : public CppUnit::TestListener {
public:
	void startTest(CppUnit::Test * test)
	{
		std::cout << "starting to measure time\n";
	}
	void endTest(CppUnit::Test * test)
	{
		std::cout << "done with measureing time\n";
	}
};

int main()
{
	CppUnit::TestSuite * suite = new CppUnit::TestSuite("mystringTest");
	suite->addTest(new CppUnit::TestCaller<mystringTest>("checkLength", &mystringTest::checkLength));
	suite->addTest(new CppUnit::TestCaller<mystringTest>("checkValue", &mystringTest::checkValue));

	CppUnit::TextTestRunner runner;
	runner.addTest(suite);

	myListener listener;
	CppUnit::TestResult result;
	result.addListener(&listener);

	runner.run(result);
	return 0;
}
