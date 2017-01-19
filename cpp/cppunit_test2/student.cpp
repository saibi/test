#include "student.h"

Student::Student(std::string nm, std::string no):name(nm), number(no) 
{
	no_of_courses = 0;
}

std::string Student::getStuName()
{
	return name;
}

std::string Student::getStuNumber()
{
	return number;
}

void Student::assignGrade(std::string co, int gr)
{
	if ( no_of_courses == MAXNUM)
	{
		std::cout << "You have exeeded the maximum number of courses!\n";
		return;
	}

	Course c(co, gr);
	course_grades[no_of_courses++] = c;
}

int Student::getGrade(std::string co)
{
	int i = 0;

	while ( i < no_of_courses )
	{
		if ( course_grades[i].getCourseName() == co )
			return (course_grades[i].getCourseGrade());

		i++;
	}

	return -1;
}

