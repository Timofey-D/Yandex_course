#include <iostream>
#include <string>

struct Specialization
{
	std::string value;
	explicit Specialization(std::string specialization)
	{
		this->value = specialization;
	}
};

struct Course
{
	std::string value;
	explicit Course(std::string course)
	{
		this->value = course;
	}
};

struct Week
{
	std::string value;
	explicit Week(std::string week)
	{
		this->value = week;
	}
};

struct LectureTitle
{
	std::string specialization;
 	std::string course;
  	std::string week;
	LectureTitle(Specialization specialization, Course course, Week week)
	{
		this->specialization = specialization.value;
		this->course = course.value;
		this->week = week.value;
	}
};


int main(void)
{

	LectureTitle title(
    		Specialization("C++"),
    		Course("White belt"),
    		Week("4th")
	);

	return 0;
}
