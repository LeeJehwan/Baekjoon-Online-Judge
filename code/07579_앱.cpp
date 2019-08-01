#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define endl '\n'

int a[105];
int cost[105];
int dp[105][10005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 10000; j++) {
			dp[i][j] = -1;
		}
	}
	dp[1][0] = 0;
	dp[1][cost[1]] = a[1];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 10000; j++) {
			if (dp[i][j] == -1) continue;
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			dp[i + 1][j + cost[i + 1]] = max(dp[i + 1][j + cost[i + 1]], dp[i][j] + a[i + 1]);

		}
	}

	int ans = 0;
	for (int i = 0; i <= 10000; i++) {
		if (dp[n][i] == -1) continue;

		if (dp[n][i] >= m) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
}