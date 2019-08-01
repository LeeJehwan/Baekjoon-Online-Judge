#include <iostream>
using namespace std;

int power(int a, int b, int c) {
	if (b == 0)
		return 1;

	int tmp = power(a, b / 2, c);
	int ret = (1LL * (tmp % c) * (tmp % c)) % c;
	if (b % 2 == 1)
		ret = (1LL * (ret % c) * (a % c)) % c;
	return ret;
}


int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int ans = power(a, b, c);

	cout << ans << endl;
}