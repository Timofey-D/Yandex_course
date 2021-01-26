#include <iostream>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int start = (A % 2 == 0 ? A : A + 1);
	for (int i = start; i <= B; i += 2)
		cout << i << " ";
	return 0;
}
