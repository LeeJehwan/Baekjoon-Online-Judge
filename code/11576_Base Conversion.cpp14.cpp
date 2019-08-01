#include <iostream>
using namespace std;


void solve(long long sum, int b) {
	if (sum == 0)
		return;

	solve(sum / b, b);
	cout << sum%b << " ";
}




int main() {
	int a, b;
	cin >> a >> b;

	int m;
	long long sum = 0;
	long long mul = 1; 
	cin >> m;
	for (int i = 0; i < m-1; i++)
		mul *= a;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		sum = sum + mul*temp;
		mul /= a;
	}

	if (sum == 0)
		cout << 0 << endl;
	else {
		solve(sum, b);
		cout << endl;
	}
}