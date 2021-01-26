#include <iostream>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int gcd = 0;
	if (A % 2 == 0 && B % 2 != 0)
		A /= 2;
	else if (A % 2 != 0 && B % 2 == 0)
		B /= 2;
	if (A == 0)
		cout << B << endl;
	else if (B == 0)
		cout << A << endl;
	else if (A % 2 == 0 && B % 2 == 0) {
		int one = A / 2;
		int two = B / 2;
		int max = one > two ? one : two;
		for (int i = 1; i <= max; i++) {
			if (one % i == 0 && two % i == 0)
				gcd = i;
		}
		cout << 2 * gcd << endl;
	}
	else {
		while (A != B) {
			if ( A > B ) 
				A = A - B;
			else
				B = B - A;
		}
		cout << A << endl;
	}
	return 0;
}
