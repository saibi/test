#ifndef _MYTEST_H_
#define _MYTEST_H_

#include "student.h"
#include <cppunit/TestCase.h>

class MyTest : public CppUnit::TestCase {
public:

	MyTest(std::string name) : CppUnit::TestCase(name) {}

	void runTest() {
		Student stu("kim", "9411");

		CPPUNIT_ASSERT( stu.getStuName() == "lee");
		CPPUNIT_ASSERT( stu.getStuNumber() == "9411");
	}
};
#endif 
