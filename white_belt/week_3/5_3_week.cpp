#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>


class Person {
public:
    void ChangeFirstName(int year, const std::string& first_name) {
        f_names[year] = first_name;
    }
    void ChangeLastName(int year, const std::string& last_name) {
        l_names[year] = last_name;
    }
    std::string GetFullName(int year) {
        std::string f_name = getCurrentNameByYear(f_names, year);
        std::string l_name = getCurrentNameByYear(l_names, year);
        return getCreateCurrentName(f_name, l_name);
    }
    std::string GetFullNameWithHistory(int year) {
        std::vector<std::string> vector_first_names = currentListNames(f_names, year);
        std::vector<std::string> vector_last_names = currentListNames(l_names, year);
        return getFullNameAndHistory(createName(vector_first_names), createName(vector_last_names));
    }
private:
    std::map<int, std::string> f_names;
    std::map<int, std::string> l_names;
    std::string getFullNameAndHistory(std::string first_name, std::string last_name) {
        if (!first_name.empty() && !last_name.empty()) {
            return first_name + " " + last_name;
        }
        else if (!first_name.empty() && last_name.empty()) {
            return first_name + " with unknown last name";
        }
        else if (first_name.empty() && !last_name.empty()) {
            return last_name + " with unknown first name";
        }
        else {
            return "Incognito";
        }
    }
    std::vector<std::string> currentListNames(const std::map<int, std::string>& names, int year) {
        std::vector<std::string> list_names;
        std::string previous;
        for (const auto & [y, n] : names) {
            if (y <= year && previous != n) {
                list_names.push_back(n);
            }
            previous = n;
        }
        return list_names;
    }
    std::string createName(std::vector<std::string>& list_names) {
        std::string name = (list_names.size() >= 1 ? list_names[list_names.size() - 1] : "");
        if (!list_names.empty()) {
            list_names.pop_back();
            name += (list_names.size() >= 1 ? " (" : "");
            for (int pos = list_names.size() - 1; pos >= 0; pos--) {
                name += list_names[pos] + (pos != 0 ? ", " : ")");
            }
        }
        return name;
    }
    std::string getCreateCurrentName(std::string& f_name, std::string& l_name) {
        if (!f_name.empty() && !l_name.empty()) {
            return f_name + " " + l_name;
        }
        else if (!f_name.empty() && l_name.empty()) {
            return f_name + " with unknown last name";
        }
        else if (f_name.empty() && !l_name.empty()) {
            return l_name + " with unknown first name";
        }
        else {
            return "Incognito";
        }
    }
    std::string getCurrentNameByYear(const std::map<int, std::string>& names, int year) {
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
    person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    std::cout << person.GetFullNameWithHistory(1940) << std::endl;
    return 0;
}
