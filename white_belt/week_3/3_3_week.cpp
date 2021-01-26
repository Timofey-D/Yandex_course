#include <iostream>
#include <vector>
#include <algorithm>

class SortedStrings {
public:
  void AddString(const std::string& s) {
  	collects.push_back(s);
  }
  std::vector<std::string> GetSortedStrings() {
	std::sort(collects.begin(), collects.end());
	return collects;
  }
private:
	std::vector<std::string> collects;
};


void PrintSortedStrings(SortedStrings& strings) {
  for (const std::string& s : strings.GetSortedStrings()) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
}


int main() {
  SortedStrings strings;
  
  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  return 0;
}

