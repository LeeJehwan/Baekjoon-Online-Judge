#include <iostream>
using namespace std;


void solve(int n) {
	if (n == 0)
		return;
	
	if (n % 2 == 0) {
		solve(-n / 2);
		cout << 0;
	}
	else {
		if (n > 0) {
			solve(-n / 2);
			cout << 1;
		}
		else {
			solve((-n + 1) / 2);
			cout << 1;
		}
	}
}

int main() {
	int n;
	cin >> n;

	if (n == 0)
		cout << 0 << endl;
	else
		solve(n);
	cout << endl;
	return 0;
}