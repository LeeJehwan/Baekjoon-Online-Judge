#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	char* str[] = { "right","wrong" };
	while (1) {
		int sum = 0;
		int a, b, c;
		cin >> a >> b >> c;
		if (!(a + b + c))
			break;
		if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
			cout << str[0] << endl;
		else
			cout << str[1] << endl;
	}

}

