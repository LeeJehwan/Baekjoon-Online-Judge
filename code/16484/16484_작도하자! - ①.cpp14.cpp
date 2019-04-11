#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main() {
	double a, b;
	cin >> a >> b;
	double ans = (a / 2.0) - b;
	cout << fixed << setprecision(1) << ans << endl;
}