#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	int a, b, c, b1, c1;
	cin >> a >> b >> c >> b1 >> c1;

	int t1,t2;
	if (b%b1 == 0)
		t1 = b / b1;
	else
		t1 = b / b1 + 1;
	if (c%c1 == 0)
		t2 = c / c1;
	else
		t2 = c / c1 + 1;

	cout << a - max(t1, t2) << endl;
}