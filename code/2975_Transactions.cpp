#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

int main() {
	while (1) {
		int a, b;
		char c;
		cin >> a >> c >> b;

		if (a == 0 && c == 'W' && b == 0)
			break;

		if (c == 'W') {
			int bal = a - b;
			if (bal < -200)
				cout << "Not allowed" << endl;
			else {
				cout << bal << endl;
			}

		}
		else if (c == 'D') {
			int bal = a + b;
			cout << bal << endl;
		}
	}

}