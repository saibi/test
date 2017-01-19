#include "mytest.h"

#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

using namespace std;

int main()
{
	MyTest test("test");

	test.runTest();
	return 0;
}

