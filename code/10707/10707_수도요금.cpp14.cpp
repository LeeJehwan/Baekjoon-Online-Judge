#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int x, y_min, y_bound, y_add, use;
	cin >> x >> y_min >> y_bound >> y_add >> use;

	int x_pay, y_pay;
	x_pay = use*x;
	if (use > y_bound) {
		y_pay = y_min + (use - y_bound)*y_add;
	}
	else
		y_pay = y_min;

	cout << min(x_pay, y_pay) << endl;


}