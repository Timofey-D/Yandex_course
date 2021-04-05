#include <iostream>
#include <string>
#include <map>
#include <exception>
#include <ctype.h>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <set>
#include <vector>
// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
    public:
        Date() {};
        Date(int year, int month, int day)
        {
            if (month <= 0 || month > 12)
            {
                throw std::runtime_error("Month value is invalid: " + std::to_string(month));
            } 
            else if (day <= 0 || day > 31)
            {
                throw std::runtime_error("Day value is invalid: " + std::to_string(day));
            }
            this->year = year;
            this->month = month;
            this->day = day;
        }
        int GetYear() const
        {
            return this->year;
        }
        int GetMonth() const
        {
            return this->month;
        }
        int GetDay() const
        {
            return this->day;
        }
    private:
        int year;
        int month;
        int day;
};

bool operator<(const Date& lhs, const Date& rhs)
{
    std::vector<int> date_1 = {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()};
    std::vector<int> date_2 = {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
    return date_1 < date_2;
}

class Database {
    public:
        void AddEvent(const Date& date, const std::string& event)
        {
            if (!event.empty())
            {
                this->table[date].insert(event);
            }
        }
        bool DeleteEvent(const Date& date, const std::string& event)
        {
            if (std::count(this->table[date].begin(), this->table[date].end(), event) == 1)
            {
                this->table[date].erase(event);
                return 1;
            }
            return 0;
        }
        int  DeleteDate(const Date& date)
        {
            int quantity = 0; 
            if (this->table.count(date) == 1)
            {
                quantity = this->table[date].size();
                this->table.erase(date);
                return quantity;
            }
            else
            {
                return quantity;
            }
        }
        void find(const Date& date) const
        {
            if (this->table.count(date) == 1)
            {
                std::set<std::string> events = this->table.at(date);
                for (const auto & event : events)
                {
                    std::cout << event << std::endl;
                }
            }
        }
        void Print() const
        {
            for (const auto & [date, events] : this->table)
            {
                for (const auto & event : events)
                {
                    std::cout << std::setfill('0') << std::setw(4) << date.GetYear() << '-' <<
                    std::setfill('0') << std::setw(2) << date.GetMonth() << '-' <<
                    std::setfill('0') << std::setw(2) << date.GetDay() << " " << 
                    event << std::endl;
                }
            }
        }
    private:
        std::map<Date, std::set<std::string>> table;
};

void getDateValue(const std::string date, int & year, int & month, int & day)
{
    std::stringstream dd;
    dd << date;
    
    bool valid = 1;

    valid = valid && (dd >> year);
    valid = valid && (dd.peek() == '-');
    dd.ignore(1);

    valid = valid && (dd >> month);
    valid = valid && (dd.peek() == '-');
    dd.ignore(1);

    valid = valid && (dd >> day);
    valid = valid && (dd.eof());
    dd.ignore(1);

    if (!valid)
    {
        throw std::runtime_error("Wrong date format: " + date);
    }
}


Date checkAndGetDate(const std::string & date_str)
{
    int year = 0;
    int month = 0;
    int day = 0;
    
    getDateValue(date_str, year, month, day);

    return {year, month, day}; 
}


int main(void) 
{
    Database db;

    std::string command;
    while (getline(std::cin, command)) 
    {
        Date date;
        // считайте команды с потока ввода и обработайте каждую
        std::stringstream command_stream;
        command_stream << command;

        std::string query;
        std::string date_str;
        std::string event;
        command_stream >> query >> date_str >> event;

        if (!date_str.empty())
        {
            try
            {
                date = checkAndGetDate(date_str);
            } catch (std::runtime_error & e)
            {
                std::cout << e.what() << std::endl;
                break;
            }
        }

        if (query == "Print")
        {
            db.Print();
        }
        else if (query == "Add")
        {
            db.AddEvent(date, event);
        }
        else if (query == "Del" && !event.empty())
        {
            if (db.DeleteEvent(date, event) == 1)
            {
                std::cout << "Deleted successfully" << std::endl;
            }
            else
            {
                std::cout << "Event not found" << std::endl;
            }
        }  
        else if (query == "Del")
        {
            std::cout << "Deleted " << db.DeleteDate(date) << " events" << std::endl;
        }
        else if (query == "Find")
        {
            db.find(date);
        }
        else if (!command.empty())
        {
            std::cout << "Unknown command: " << query << std::endl;
            break;
        }
    }
    return 0;
}
