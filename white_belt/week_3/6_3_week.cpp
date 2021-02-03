#include <iostream>
#include <string>

class ReversibleString {
	public:
		ReversibleString() {}
		ReversibleString(const std::string& str) {
			ReversibleString::str = str;
		}
		void Reverse() {
			std::string reverse;
			
			for (int pos = str.length() - 1; pos >= 0; pos--) {
			
				reverse += str[pos];

			}
			
			str = reverse;
		}
		std::string ToString() const {
			return str;
		}
	private:
		std::string str;
};


int main(int argc, const char * argv[]) {
  ReversibleString s("live");
  s.Reverse();
  std::cout << s.ToString() << std::endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  std::string tmp = s_ref.ToString();
  std::cout << tmp << std::endl;
  
  ReversibleString empty;
  std::cout << '"' << empty.ToString() << '"' << std::endl;
  
  return 0;
}

