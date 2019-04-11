#include <iostream>
using namespace std;


int main() {
	int n;
	cin >> n;

	long long ans = 0;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;

		int s = tmp % 10;
		tmp /= 10;

		int tmp2 = tmp;
		for (int j = 1; j < s; j++)
			tmp2 = tmp2 * tmp;

		if (s == 0)
			tmp2 = 1;

		ans += tmp2;
	}

	cout << ans << endl;
}