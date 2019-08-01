#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main() {
	double a, b;
	cin >> a >> b;
	double ans = a / b;
	cout << fixed << setprecision(6) << ans << endl;
}