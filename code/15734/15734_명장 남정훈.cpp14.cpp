#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int l, r, a;
	cin >> l >> r >> a;
	if (l < r) {
		int tmp = r - l;
		if (a >= tmp) {
			l += tmp;
			a -= tmp;
			cout << (a / 2 + l)*2 << endl;
			return 0;
		}
		l += a;
		cout << 2 * l << endl;
		return 0;
	}
	else if (r == l ) {
		cout << (r+a/2)*2 << endl;
	}
	else {
		int tmp = l - r;
		if (a >= tmp) {
			r += tmp;
			a -= tmp;
			cout << (a / 2 + r)*2 << endl;
			return 0;
		}
		r += a;
		cout << 2 * r << endl;
		return 0;
	}

}

