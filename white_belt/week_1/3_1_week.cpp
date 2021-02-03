#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double D = (b * b) - 4 * a * c;
	double x1, x2;
	if (a == 0 && b != 0) {
		if (c != 0)
			cout << -(c / b) << endl;
		else if (c == 0)
			cout << -(1 / b) << endl;
	}
	else if ( a != 0 && b != 0 && (c != 0 || c == 0) ) {
		if (D > 0) {
			x1 = (-b + sqrt(D)) / (2 * a);
			x2 = (-b - sqrt(D)) / (2 * a);
			cout << x1 << " " << x2 << endl;	
		}
		else if (D == 0)
			cout << (-b + sqrt(D)) / (2 * a) << endl;
	}
	if ( a != 0 && b == 0) {
		if (c == 0)
			cout << sqrt(-1 / a) << endl;
		else if (c != 0) {
			if ( (c == 1 || c == -1) && (a == 1 || a == -1) )
				cout << -c << " " << c << endl;
			if (c < 0)
				c *= -1;
			for (int i = 0; i <= c / 2; i++) {
				if (i * i == c) 
					cout << -sqrt(c) << " " << sqrt(c) << endl;
			}
		}
	}
}
