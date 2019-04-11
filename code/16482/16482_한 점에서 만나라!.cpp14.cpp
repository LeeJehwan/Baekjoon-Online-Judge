#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	double t1 = (double)d / (c - d);
	double t2 = (double)e / (a - e);
	double t3 = t1 * t2 + 1;
	double ans = (double)b / t3;
	printf("%lf\n", ans);

}