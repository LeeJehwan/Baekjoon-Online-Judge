#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define endl '\n'

int a[205];
int dp[205][205];

int solve(int s, int e) {
	if (s == e)
		return dp[s][e] = 0;
	if (dp[s][e] != 1e9)
		return dp[s][e];

	for (int i = s; i < e; i++) {
		dp[s][e] = min(dp[s][e], solve(s, i) + solve(i + 1, e) + (a[s] != a[i + 1]));
	}
	return dp[s][e];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = 1e9;
		}
	}
	cout << solve(1, n);
}