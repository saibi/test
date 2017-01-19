#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

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
		CPPUNIT_ASSERT_MESSAGE("String Length Non-Zero", s.size() == 0);
	}

	void checkValue()
	{
		mystring s;
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


CPPUNIT_TEST_SUITE_REGISTRATION( mystringTest2 );

int main()
{
	CppUnit::Test *test = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
	CppUnit::TextTestRunner runner;
	runner.addTest(test);
	runner.run();

	return 0;
}
