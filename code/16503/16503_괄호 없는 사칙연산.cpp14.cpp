#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <set>
using namespace std;


int calc(int n1, int n2, char op) {
	if (op == '+') {
		return n1 + n2;
	}
	else if (op == '-') {
		return n1 - n2;
	}
	else if (op == '*') {
		return n1 * n2;
	}
	else if (op == '/') {
		if (n1 < 0 || n2 < 0) {
			return -(abs(n1) / abs(n2));
		}
		else {
			return n1 / n2;
		}
	}
}


int main() {
	int a, b, c;
	char c1, c2;
	cin >> a >> c1 >> b >> c2 >> c;

	int res = calc(a, b, c1);
	res = calc(res, c, c2);

	int res2 = calc(b, c, c2);
	res2 = calc(a, res2, c1);

	if (res > res2) {
		cout << res2 << endl;
		cout << res << endl;
	}
	else {
		cout << res << endl;
		cout << res2 << endl;
	}
}