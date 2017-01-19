#ifndef _TEST_STUDENT_H_
#define _TEST_STUDENT_H_

#include <iostream>
#include <string>

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestRunner.h>

#include "student.h"

class StudentTestCase : public CppUnit::TestCase {
public:
	StudentTestCase(std::string name) : TestCase(name) {}

	void testConstructor();

	void testAssignAndRetriveGrades();

	static Test *suite();
};


#endif 
