#include <iostream>
#include <map>
#include <string>


class Person {
public:
  void ChangeFirstName(int year, const std::string& first_name) {
	Person::first_name[year] = first_name;
  }
  void ChangeLastName(int year, const std::string& last_name) {
	Person::last_name[year] = last_name;
  }
  std::string GetFullName(int year) {
	std::string full_name;
	std::string f_name = getNameByYear(first_name, year); 
	std::string l_name = getNameByYear(last_name, year);
	if (!f_name.empty() && !l_name.empty()) {
		full_name = f_name + " " + l_name;
	}
	else if (!f_name.empty() && l_name.empty()) {
		full_name = f_name + " with unknown last name";
	}
  	else if (f_name.empty() && !l_name.empty()) {
		full_name = l_name + " with unknown first name";
	}
  	else {
		full_name = "Incognito";
	}
	return full_name;
  }
private:
	std::map<int, std::string> first_name;
	std::map<int, std::string> last_name; 
	std::string getNameByYear(const std::map<int, std::string>& names, int year) {
		std::string name;
		for (const auto & [y, n] : names) {
			if (y <= year) {
				name = n;
			}
		}
		return name;
	}
};


int main(int argc, const char * argv[]) {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    std::cout << person.GetFullName(year) << std::endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullName(year) << std::endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullName(year) << std::endl;
  }
  
  return 0;
}
