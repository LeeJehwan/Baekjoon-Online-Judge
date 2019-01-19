#include <iostream>
using namespace std;
#define endl '\n'

int get_sum(int n) {
	int sum = n;
	while (1) {
		if (n == 0)
			break;
		sum += n % 10;
		n /= 10;
	}
	return sum;
}


int main() {
	int n;
	cin >> n;

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (get_sum(i) == n) {
			ans = i;
			break;
		}
	}

	cout << ans << endl;
}