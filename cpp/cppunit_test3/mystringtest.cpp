#include <cppunit/TestCase.h>
#include <cppunit/ui/text/TextTestRunner.h>

#include "mystring.h"


class mystringTest:public CppUnit::TestCase
{
      public:

	void runTest()
	{
		mystring s;
		CPPUNIT_ASSERT_MESSAGE("String Length Zero", s.size() == 0);
	}
};

int main()
{
	mystringTest test;
	CppUnit::TextTestRunner runner;
	runner.addTest(&test);

	runner.run();
	return 0;
}
