#include "teststudent.h"
#include <assert.h>

void StudentTestCase::testConstructor()
{
	Student stu("kim", "9411");

	std::string student_name = stu.getStuName();
	assert(student_name == "kim");

	std::string student_number = stu.getStuNumber();
	assert(student_number == "9411");
}

void StudentTestCase::testAssignAndRetriveGrades()
{
	Student stu("Jimmy", "9463");

	stu.assignGrade("cs2102", 60);
	stu.assignGrade("cs2103", 70);
	stu.assignGrade("cs3214s", 80);

	assertEquals(60, stu.getGrade("cs2102"));
	assertEquals(70, stu.getGrade("cs2103"));
	assertEquals(-1, stu.getGrade("cs21002"));
}


Test * StudentTestCase::suite()
{
	TestSuite *testSuite = new TestSuite("StudentTestCase");

	testSuite->addTest( new TestCaller("testConstructor", &StudentTestCase::testConstructor));
	testSuite->addTest( new TestCaller("testAssignAndRetriveGrade", &StudentTestCase::testAssignAndRetriveGrades));

	return testSuite;
}


int main(int argc, char *argv[])
{
	if ( argc != 2 )
	{
		std::cout << "usage : tester name_of_class_being_test" << std::endl;
		exit(1);
	}

	TestRunner runner;

	runner.addTest(argv[1], StudentTestCase::suite());
	runner.run(argc, argv);

	return 0;
}


