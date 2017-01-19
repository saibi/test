#ifndef _COURSE_H_
#define _COURSE_H_

#include <string>

class Course {
public:
	Course();

	Course(std::string nm, int gr);

	std::string getCourseName();

	int getCourseGrade();

private:

	std::string course_name;
	int grade;
};
#endif 
	

