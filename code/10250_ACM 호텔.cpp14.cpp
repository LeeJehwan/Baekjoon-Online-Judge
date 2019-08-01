#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;

		int r = c % a;
		int q = c / a;
		
		if (r != 0)
			cout << r;
		else {
			cout << a;
			q--;
		}

		if (q + 1 < 10)
			cout << 0;
		cout << q + 1 << endl;
	}
}