#include <iostream>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;

	int tmp = n % 100;
	n -= tmp;

	int i;
	for (i = 0; i < 100; i++) {
		if (n%k == 0)
			break;
		n++;
	}

	if (i < 10)
		cout << 0;
	cout << i << endl;

}