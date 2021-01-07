#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<double> result(10, 1);
	cout << result.size() << endl;
	result.assign(1, 0);
	cout << result.size() << endl;
	return 0;
}
