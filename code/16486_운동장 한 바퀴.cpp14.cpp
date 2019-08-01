#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
double PI = 3.141592;

int main() {
	double a, b;
	cin >> a >> b;
	double ans = 2 * a + 2 * b*PI;
	cout << fixed << setprecision(6) << ans << endl;
}