#include <iostream>
using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	if ( ((a >= b && a >= c) && b >= c) || ((b >= a && b >= c) && a >= c) )
                cout << c;
        else if ( ((a >= b && a >= c) && c >= b) || ((c >= a && c >= b) && a >= b) )
                cout << b;
        else if ( ((c >= a && c >= b) && b >= a) || ((b >= a && b >= c) && c >= a) )
                cout << a;
	return 0;
}

