#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	double a, b, c, m;
	cin >> a >> b >> c >> m;
	double ans = (m * c*c + (b - m)*a*a)/b - m*(b-m);
	printf("%lf\n", ans);

}