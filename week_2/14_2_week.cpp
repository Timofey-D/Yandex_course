#include <iostream>
#include <vector>
#include <string>
#include <map>

int main(int argc, const char * argv[]) {
	int Q;
	std::cin >> Q;

	std::map<std::vector<std::string>, int> list_routes;	
	std::vector<std::string> list_stops;

	int ID = 1;

	while (Q != 0) {
		
		int N;
		std::cin >> N;
		
		while (N != 0) {

			std::string stop;
			std::cin >> stop;
			
			list_stops.push_back(stop);
		
			N--;
			
		}
	
		if (list_routes.count(list_stops) == 0) {	

			list_routes[list_stops] = ID;
			std::cout << "New bus " << ID++ << std::endl;
		
		}
		else {
			
			std::cout << "Already exists for " << list_routes[list_stops] << std::endl; 

		}

		list_stops.clear();
		Q--;

	}

	return 0;
}
