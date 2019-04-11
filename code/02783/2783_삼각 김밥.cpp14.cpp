#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	double x, y;
	cin >> x >> y;

	double temp = (x / y) * 1000;
	double arr[101];

	arr[0] = temp;
	double m = arr[0];
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		double tx, ty;
		cin >> tx >> ty;
		double tmp = (tx / ty) * 1000.0;
		arr[i] = tmp;
		m = min(m, arr[i]);
	}
	printf("%.2lf\n", m);

}