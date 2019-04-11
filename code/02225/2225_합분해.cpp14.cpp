#include <iostream>
using namespace std;

#define MOD 1000000000
long long dp[201][201];
int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= k; i++)
		dp[0][i] = 1LL;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}

	cout << dp[n][k] << endl;
}