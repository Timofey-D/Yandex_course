#include <iostream>
#include <vector>

int main() {
	int n, q = 0, avr = 0;
	std::cin >> n;
	std::vector<int> temp(n, 0);
	for (auto & item : temp) {
		std::cin >> item;
		avr += item;
	}
	avr /= n;
	for (int i = 0; i < n; i++) {
		if (temp[i] > avr)
			q++;
	}
	std::cout << q << std::endl;
	for (int i = 0; i < n; i++) {
		if (temp[i] > avr)
			std::cout << i << " ";
	}
	std::cout << std::endl;
}
