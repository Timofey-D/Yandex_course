#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
	
	int number;
	std::cin >> number;
	
	std::string balances; 
	
	if (number == 0) {
		
		std::cout << 0 << std::endl;	

	}
	else {

		while (number != 0) {
		
			balances = std::to_string((number % 2)) + balances;
			number /= 2;
	
		}
		
		std::cout << balances << std::endl;
	}

	return 0;
}

