#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define endl '\n'
#define MOD 1000000007

int a[10005];
long long dp[2][10005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (a[0] < 1)
		dp[0][0] = 1;
	else
		dp[0][0] = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= n / 2; j++) {
			dp[1][j] = 0;
		}

		if (a[i] == -1) {
			dp[1][0] = (dp[0][0] + dp[0][1]) % MOD;
			for (int j = 1; j <= n / 2; j++) {
				dp[1][j] = (dp[0][j] + dp[0][j - 1] + dp[0][j + 1]) % MOD;
			}
		}
		else if (a[i] == 0) {
			dp[1][0] = (dp[0][0] + dp[0][1]) % MOD;
		}
		else {
			dp[1][a[i]] = (dp[0][a[i]] + dp[0][a[i] - 1] + dp[0][a[i] + 1]) % MOD;
		}
		swap(dp[0], dp[1]);
	}
	cout << dp[0][0] << endl;
}