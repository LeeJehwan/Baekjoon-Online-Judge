#include <iostream>
using namespace std;

int main() {
	long long x, y;
	cin >> x >> y;
	long long z = (y * 100 / x);
	if (z >= 99) {
		cout << -1 << endl;
		return 0;
	}

	int tmp;
	long long r = 2000000000;
	long long l = 0;
	bool flag = false;
	while (l < r) {
		long long mid = (r + l) / 2;
		tmp = (y + mid) * 100 / (x + mid);
		if (tmp > z) {
			flag = true;
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	if (!flag)
		cout << -1 << endl;
	else
		cout << r << endl;

}