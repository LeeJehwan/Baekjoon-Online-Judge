#include <iostream>
using namespace std;

int main() {
	int p, n, m;
	cin >> p >> n >> m;
	int t = p * n;
	if (m >= t) {
		cout << 0;
	}
	else {
		cout << t - m;
	}
}