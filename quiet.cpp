#include <iostream>
#include <vector>
#include <string>

int main() {
	std::vector<std::string> queue;
	int Q, number;
	std::string action;
	std::cin >> Q;
	int worry = 0;
	while (Q != 0) {
		std::cin >> action;
		if (action != "WORRY_COUNT")
			std::cin >> number;
		if (action == "COME") {
			queue.resize(queue.size() + number, "QUIET");
		}
		else if (action == "WORRY" || action == "QUIET") {
			queue[number] = action;
		}
		else if (action == "WORRY_COUNT") {
			worry = 0;
			for (int i = 0; i < queue.size(); i++) {
				if (queue[i] == "WORRY")
					worry++;			
			}
			std::cout << worry << std::endl;
		}
		Q--;
	}
}	
