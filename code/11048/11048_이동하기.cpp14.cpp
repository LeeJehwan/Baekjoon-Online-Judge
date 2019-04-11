#include <iostream>
#include <algorithm>
using namespace std;

int candy[1005][1005];
int dp[1005][1005];

int solve(int n, int m) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] = max(dp[i][j - 1] + candy[i][j], dp[i - 1][j] + candy[i][j]);
	return dp[n][m];

}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> candy[i][j];
	cout << solve(n, m) << endl;
}