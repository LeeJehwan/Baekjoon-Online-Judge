#include <iostream>
using namespace std;

long long dp[90];
long long pinary(int n) {
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << pinary(n) << endl;
}