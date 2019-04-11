#include <iostream>
using namespace std;

int main() {
	int k, d1, d2;
	cin >> k >> d1 >> d2;

	if (d1 == d2) {
		cout << k * k << endl;
		return 0;
	}
	else {
		int diff = d1 - d2;
		double a = (double)diff / (2.0);
		double ans = (double)k*k - a * a;
		cout << ans << endl;
	}
}