#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <string>
#include "course.h"

const int MAXNUM = 20;

class Student {
public:

	Student(std::string nm, std::string no);

	std::string getStuName();
	std::string getStuNumber();
	void assignGrade(std::string co, int gr);
	int getGrade(std::string co);

private:
	std::string name;
	std::string number;
	Course course_grades[MAXNUM];
	int no_of_courses;
};

#endif 
