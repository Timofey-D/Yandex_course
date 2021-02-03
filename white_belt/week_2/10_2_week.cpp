#include <iostream>
#include <vector>
#include <string>


int main() {
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int Q = 0;
	std::cin >> Q;
	int order = 0;
	std::vector<std::vector<std::string>> previous;
	std::vector<std::vector<std::string>> current(days[order]);
	while (Q != 0) {
		int i;
                std::string s;
		std::string action;
                std::cin >> action;
		if (action != "NEXT")
			std::cin >> i;	
		if (action == "NEXT") {
			order = (order + 1) % 12;
			previous = current;
			current.resize(days[order]);
			for (int i = current.size(); i < previous.size(); i++) {
				current[ current.size() - 1].insert(
					current[ current.size() - 1 ].end(), 
					begin(previous[i]), 
					end(previous[i]));				
			}		
		}
		else if (action == "ADD") {
			std::cin >> s;
			current[i - 1].push_back(s);
		}
		else if (action == "DUMP") {
			std::cout << current[i - 1].size() << " ";
			for (int deal = 0; deal < current[i - 1].size(); deal++)
				std::cout << current[i - 1][deal] << " ";
			std::cout << std::endl;
		}
		Q--;
	}
	return 0;
}
