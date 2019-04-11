#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1005][1005];

void solve(int n, int m) {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if(dp[i][j])
				dp[i][j] = min({ dp[i - 1][j] ,dp[i][j - 1],dp[i - 1][j - 1] }) + dp[i][j];
			ret = max(dp[i][j], ret);
		}
	}
	cout << ret*ret << endl;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &dp[i][j]);
	
	solve(n, m);
}