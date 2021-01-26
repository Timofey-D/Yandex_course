#include <iostream>
#include <string>
#include <map>


std::map<char, int> BuildCharCounters(std::string word) {
	std::map <char, int> result;
	for (char & sym : word) {
		result[sym]++;
	}
	return result; 	
}

int main(int argc, const char * argv[]) {
	int N;
	std::cin >> N;
	std::string word;
	std::map<char, int> word_1;
	std::map<char, int> word_2;
	while (N != 0) {
		std::cin >> word;
		word_1 = BuildCharCounters(word);
		std::cin >> word;
		word_2 = BuildCharCounters(word);
		std::cout << (word_1 == word_2 ? "YES" : "NO") << std::endl;
		N--;
	}
	return 0;
}
