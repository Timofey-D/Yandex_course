#include <iostream>
#include <set>
#include <map>
#include <string>

int main(int argc, const char * argv[]) {
	
	int Q;
	std::cin >> Q;
	
	std::map<std::set<std::string>, int> list_routes;

	int ID = 0;

	while (Q != 0) {
		
		int N;
		std::cin >> N;		
	
		std::set<std::string> stops;
		
		while (N != 0) {
		
			std::string stop;
			std::cin >> stop;

			stops.insert(stop);			
		
			N--;		

		}
		
		if (list_routes.count(stops) == 0) {
		
			list_routes[stops] = ++ID;
			
			std::cout << "New bus " << ID << std::endl;
			
		}
		else {

			std::cout << "Already exists for " << list_routes[stops] << std::endl;			

		}

		Q--;
		
	}	

	return 0;
}
