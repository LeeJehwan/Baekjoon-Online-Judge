#include <iostream>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	int count = 0;

	while (1) {
		if (n <= 1 || m <= 0)
			break;
		n -= 2;
		m -= 1;
		count++;
	}

	k -= n;
	k -= m;
	if (k <= 0) {
		cout << count << endl;
		return 0;
	}

	while (1) {
		if (k <= 0)
			break;
		k -= 3;
		count--;
	}
	cout << count << endl;
	return 0;
}