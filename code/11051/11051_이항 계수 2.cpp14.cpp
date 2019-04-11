#include <iostream>
using namespace std;

#define MOD 10007
long long dp[1001][1001];

long long bico(int n, int k) {
	if (n == k || k == 0)
		return dp[n][k] = 1;
	
	if (dp[n][k])
		return dp[n][k];

	return dp[n][k] = (bico(n - 1, k) + bico(n - 1, k - 1)) % MOD;
}


int main() {
	int n, k;
	cin >> n >> k;

	long long ans = bico(n, k);
	cout << ans << '\n';
}