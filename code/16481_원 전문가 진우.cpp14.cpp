#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int r1, r2, r3;
	cin >> r1 >> r2 >> r3;
	int a = r1 * r2 * r3;
	int b = r2 * r3 + r1 * r3 + r2 * r1;
	double ans = (double)a / b;

	printf("%lf\n", ans);
}