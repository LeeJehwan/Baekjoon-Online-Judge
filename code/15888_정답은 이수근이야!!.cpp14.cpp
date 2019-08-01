#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool chk(int n) {
	if (n <= 1)
		return false;
	int t = n;
	while (1) {
		if (t == 1)
			break;
		if (t % 2 != 0)
			return false;
		t /= 2;
	}
	return true;
}



int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int t = b*b - 4 * a*c;
	if (t < 0 || t==0) {
		cout << "둘다틀렸근" << '\n';
		return 0;
	}
	double tmp = sqrt(t);
	int tmp2 = (int)tmp;
	if(tmp-tmp2 > 1e-6) {
		cout << "둘다틀렸근" << '\n';
		return 0;
	}

	int root1 = -b + tmp2;
	if(root1%(2*a) != 0) {
		cout << "둘다틀렸근" << '\n';
		return 0;
	}
	root1 /= (2*a);

	int root2 = -b - tmp2;
	if (root2% (2 * a) != 0) {
		cout << "둘다틀렸근" << '\n';
		return 0;
	}
	root2 /= (2 * a);

	if (!chk(root1)) {
		cout << "정수근" << '\n';
		return 0;
	}
	
	if (!chk(root2)) {
		cout << "정수근" << '\n';
		return 0;
	}
	if (chk(root1) && chk(root2)) {
		cout << "이수근" << '\n';
		return 0;
	}
	cout << "둘다틀렸근" << '\n';
}