#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct Student
{
	std::string first_name;
	std::string last_name;
	int day;
	int month;
	int year;
};


int main(void)
{
	std::vector<Student> students;
	
	int Num_students;
	std::cin >> Num_students;

	while (Num_students-- != 0)
	{
		Student student;
		std::cin >> student.first_name >> student.last_name >> 
				student.day >> student.month >> student.year;
		students.push_back(student);
	}

	int M_queries;
	std::cin >> M_queries;	

	while (M_queries-- != 0)
	{
		std::string action;
		int n;
		std::cin >> action >> n;
				
		if (action == "name" && n > 0 && n <= students.size())
		{			
			std::cout << students[n - 1].first_name << " " << students[n - 1].last_name << std::endl;			
		}
		else if (action == "date" && n > 0 && n <= students.size())
		{
			std::cout << students[n - 1].day << "." << students[n - 1].month << "." << students[n - 1].year << std::endl;
		}
		else
		{
			std::cout << "bad request" << std::endl;
		}
	}
	
	return 0;	
}
