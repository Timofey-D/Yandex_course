#include <iostream>
#include <string>
#include <set>
#include <map>


int main(int argc, const char * argv[]) {
	int Q;
	std::cin >> Q;

	std::map<std::string, std::set<std::string>> synonyms;
	
	while (Q != 0) {
	
		std::string action, word_1, word_2;
		std::cin >> action;

		if (action == "ADD") {

			std::cin >> word_1 >> word_2;
			
			synonyms[word_1].insert(word_2);
			synonyms[word_2].insert(word_1);

		}
		else if (action == "COUNT") {
			
			std::cin >> word_1;

			std::cout << synonyms[word_1].size() << std::endl;
			
		}
		else if (action == "CHECK") {

			std::cin >> word_1 >> word_2;

			if ( synonyms[word_1].count(word_2) || synonyms[word_2].count(word_1) ) {

				std::cout << "YES" << std::endl;
			
			}
			else {

				std::cout << "NO" << std::endl;

			}
							
		}
		
		
		Q--;
	}
	
	return 0;
}
