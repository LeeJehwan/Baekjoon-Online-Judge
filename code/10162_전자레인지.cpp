#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	int a = 300, b = 60, c = 10;
	int a_cnt = 0, b_cnt = 0, c_cnt = 0;

	a_cnt = t / a;
	t -= a * a_cnt;
	b_cnt = t / b;
	t -= b * b_cnt;
	c_cnt = t / c;
	if (t % c != 0) {
		cout << -1;
		return 0;
	}

	cout << a_cnt << " " << b_cnt << " " << c_cnt << endl;

}