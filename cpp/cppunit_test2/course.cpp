#include "course.h"

Course::Course()
{
	course_name = "";
	grade = -1;
}

Course::Course(std::string nm, int gr) : course_name(nm) 
{
	grade = gr;
}

std::string Course::getCourseName()
{
	return course_name;
}


int Course::getCourseGrade()
{
	return grade;
}


