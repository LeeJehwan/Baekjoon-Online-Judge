#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long step = 0;
	long long sum = 0;
	for (int i = 1; i <= n; i+= step) {
		int q = (n - 1) / i;
		int r = (n - 1) % i;

		if (q == 0)
			step = 1;
		else
			step = r / q + 1;
		sum += (q + 1)*step;
	}
	cout << sum << endl;
}