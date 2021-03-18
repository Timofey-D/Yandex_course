#include <iostream>
#include <string>
// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
        int GetYear() const;
        int GetMonth() const;
        int GetDay() const;
};

bool operator<(const Date& lhs, const Date& rhs);

class Database {
public:
        void AddEvent(const Date& date, const std::string& event);
        bool DeleteEvent(const Date& date, const std::string& event);
        int  DeleteDate(const Date& date);
        void find(const Date& date) const;
        void Print() const;
};

 
std::string getCommand(std::string command)
{
    std::string command = "";
    
    for (int i = 0; i < command.length(); i++)
    {
        
    }
}


int main(void) {
        Database db;
        
        std::

        std::string command;
        while (getline(std::cin, command)) 
        {
                // Считайте команды с потока ввода и обработайте каждую
                
        }

        return 0;
}
