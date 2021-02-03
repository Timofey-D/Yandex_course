#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>


void new_bus(std::map<std::string, std::vector<std::string>>& list_buses, 
		std::vector<std::string>& alphabet_order) {
	std::string bus;
	int stop_count;
        std::cin >> bus >> stop_count;
	std::vector<std::string> stop_list;
        std::string stop;
        while (stop_count != 0) { 
		std::cin >> stop;
                stop_list.push_back(stop);
                stop_count--;
        }
        list_buses[bus] = stop_list;
       	alphabet_order.push_back(bus);
}


void buses_for_stop(std::map<std::string, std::vector<std::string>>& list_buses,
                std::vector<std::string>& alphabet_order) {
	std::string stop;
        std::cin >> stop;
        bool flag = 0;
        for (auto & [key, value] : list_buses) {
		if (std::count(value.begin(), value.end(), stop)) {
                
			flag = 1;
		
		}
       	}
       	if (flag == 1) {
		for (auto & bus : alphabet_order) {
                	if (std::count(list_buses[bus].begin(), list_buses[bus].end(), stop))
				std::cout << bus << " ";
		}
		std::cout << std::endl;
	}
	else
		std::cout << "No stop" << std::endl;
}


void stops_for_bus(std::map<std::string, std::vector<std::string>>& list_buses,
                std::vector<std::string>& alphabet_order) {
	std::string bus;
        std::cin >> bus;
        if (list_buses.count(bus) == 1) {
		for (auto & stop : list_buses[bus]) {
			std::cout << "Stop " << stop << ": ";
         		bool flag = 0;	
                        for (auto & buses : alphabet_order) {
                        	if (buses != bus && std::count(list_buses[buses].begin(), list_buses[buses].end(), stop)) {
					flag = 1;
                                        std::cout << buses << " ";
                                }
                        }
			if (flag == 0) {
		
				std::cout << "no interchange";
		
			}                                          
			std::cout << std::endl;
		}
       	}
        else {
	
		std::cout << "No bus" << std::endl;

	}
}


void all_buses(std::map<std::string, std::vector<std::string>>& list_buses) {
	if (list_buses.empty()) {
		std::cout << "No buses" << std::endl;
	}
	else {
		for (auto & item : list_buses) {
			std::cout << "Bus " << item.first << ": ";
			for (auto & stop : item.second) {
				std::cout << stop << " ";                                      
			}
			std::cout << std::endl;                            
		}
	}
}


int main(int argc, const char * argv[]) {
	int Q;
	std::cin >> Q;
	std::map<std::string, std::vector<std::string>> list_buses;
	std::vector<std::string> alphabet_order;
	while (Q != 0) {
		std::string action;
		std::cin >> action;
		if (action == "NEW_BUS") {

			new_bus(list_buses, alphabet_order);

		}
		else if (action == "BUSES_FOR_STOP") {

			buses_for_stop(list_buses, alphabet_order);			

		}
		else if (action == "STOPS_FOR_BUS") {

			stops_for_bus(list_buses, alphabet_order);

		}
		else if (action == "ALL_BUSES") {

			all_buses(list_buses);

		}
		Q--;
	} 
	return 0;
}
