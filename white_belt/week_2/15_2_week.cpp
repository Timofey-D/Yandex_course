#include <iostream>
#include <set>
#include <string>

int main(int argc, const char * argv[]) {
	int N;
	std::cin >> N;
	
	std::set<std::string> list_numbers;

	while(N != 0) {
		
		std::string number;
		std::cin >> number;

		list_numbers.insert(number);

		N--;

	}

	std::cout << list_numbers.size() << std::endl;

	return 0;
}
