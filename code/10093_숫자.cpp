#include <iostream>
#include <string>
using namespace std;

int main() {
	unsigned long long a, b;
	unsigned long long d;
	cin >> a >> b;
	if (a > b) {
		d = a - b - 1;
		b++;
		cout << d << endl;
		while (1) {
			if (b == a)
				break;
			cout << b << " ";
			b++;
		}
	}
	else if (a < b) {
		d = b - a - 1;
		a++;
		cout << d << endl;
		while (1) {
			if (b == a)
				break;
			cout << a << " ";
			a++;
		}
	}
	else {
		cout << 0;
	}
	cout << endl;
}
