#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double s = (a + b + c) / 2.0;
	double area = sqrt(s*(s - a)*(s - b)*(s - c));
	double R = (a * b * c) / (4.0 * area);
	double r = sqrt((s - a)*(s - b)*(s - c) / s);
	double d = sqrt(R*(R - 2 * r));
	if ((R - 2 * r) < 1e-9)
		d = 0;
	double k = R + r;

	cout << fixed << setprecision(12) << area << endl;
	cout << fixed << setprecision(12) << R << endl;
	cout << fixed << setprecision(12) << r << endl;
	cout << fixed << setprecision(12) << d << endl;
	cout << fixed << setprecision(12) << k << endl;

	
}