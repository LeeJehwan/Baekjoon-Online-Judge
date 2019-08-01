#include <iostream>
using namespace std;

#define MOD 1000000007
long long dp[55];
int main() {
	int n;
	cin >> n;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + 1) % MOD;
	}

	cout << dp[n] << endl;
	
}