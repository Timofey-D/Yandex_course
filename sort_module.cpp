#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

void printVector(const std::vector<int>& numbers) {
	
	for (const auto & number : numbers) {

		std::cout << number << " ";		

	}

	std::cout << std::endl;

}


int main(int argc, const char * argv[]) {
	
	int N;
	std::cin >> N;
	
	std::vector<int> numbers;

	while (N != 0) {
	
		int num;
		std::cin >> num;

		numbers.push_back(num);

		N--;

	}

	std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
		
		return (std::abs(a) < std::abs(b));	

	});

	printVector(numbers);

	return 0;
}
