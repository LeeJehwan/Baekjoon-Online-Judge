#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

int main() {
	long long c;
	int k;
	cin >> c >> k;

	long long a = 1;
	for (int i = 0; i < k; i++) {
		a *= 10;
	}

	long long r = c % a;
	c -= r;
	if ((r / (a / 10)) >= 5)
		c += a;

	cout << c << endl;


}