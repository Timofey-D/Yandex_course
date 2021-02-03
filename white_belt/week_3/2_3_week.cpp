#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void printVector(const std::vector<std::string> & vec) {
	
	for (const auto & item : vec) {

		std::cout << item << " ";
	
	}

	std::cout << std::endl;

}

int main(int argc, const char * argv[]) {
		
	int N;
	std::cin >> N;
		
	std::vector<std::string> symbols;

	while (N != 0) {

		std::string sym;
		std::cin >> sym;

		symbols.push_back(sym);

		N--;

	}

	std::sort(symbols.begin(), symbols.end(), [](std::string a, std::string b){
		
		for (auto & sym : a) {
			sym = tolower(sym);
		}
		
		for (auto & sym : b) {
			sym = tolower(sym);
		} 
		
		return a < b;

	});

	printVector(symbols);

	return 0;
}

