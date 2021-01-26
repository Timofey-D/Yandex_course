#include <iostream>
#include <string>
#include <map>

int main(int argc, const char * argv[]) {
	int Q;
	std::cin >> Q;
	std::string action;
	std::map<std::string, std::string> directory;
	while (Q != 0) {
		
		std::cin >> action;		

		if (action == "CHANGE_CAPITAL") {

			std::string country;
			std::string new_capital;
			std::cin >> country >>  new_capital;
				
			if (directory.count(country) == 0) {
					
				directory[country] = new_capital;
				std::cout << "Introduce new country " << country << " with capital " << new_capital << std::endl;					
	
			}
			else if (directory[country] == new_capital) {
				
				std::cout << "Country " << country << " hasn't changed its capital" << std::endl;

			}
			else if (directory[country] != new_capital) {
				
				std::string old_capital = directory[country];
				directory[country] = new_capital;
				std::cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << std::endl;
			}	

		}
		else if (action == "RENAME") {
					
			std::string old_country_name;
			std::string new_country_name;
			std::cin >> old_country_name >> new_country_name;

			if ( (new_country_name == old_country_name) || directory.count(new_country_name) == 1 || directory.count(old_country_name) == 0) {
					
				std::cout << "Incorrect rename, skip" << std::endl;
				
			}
			else {
				
				std::string capital = directory[old_country_name];
				directory.erase(old_country_name);
				directory[new_country_name] = capital;
				std::cout << "Country " << old_country_name << " with capital " << directory[new_country_name] << " has been renamed to " << new_country_name << std::endl;

			}
		
		}
		else if (action == "ABOUT"){
			
			std::string country;
			std::cin >> country;

			if (directory.count(country) == 0) {
	
				std::cout << "Country " << country << " doesn't exist" << std::endl;
	
			}
			else {
	
				std::cout << "Country " << country << " has capital " << directory[country] << std::endl; 
	
			}

		
		}
		else if (action == "DUMP") {
			
			if (directory.size() == 0) {

				std::cout << "There are no countries in the world" << std::endl;	
			
			}
			else {
		
				for (auto & item : directory) {
					std::cout << item.first << "/" << item.second << " ";
				}
				
				std::cout << std::endl;
				
			}
		}

		Q--;

	}
	return 0;
}
