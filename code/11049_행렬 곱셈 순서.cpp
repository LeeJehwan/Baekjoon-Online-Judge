#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

int dp[505][505];
int mat[505][2];
int solve(int s, int e) {
	if (s == e)
		return dp[s][e] = 0;
	if (dp[s][e] != 1e9)
		return dp[s][e];

	for (int k = s; k < e; k++) {
		int add = mat[s][0] * mat[k][1] * mat[e][1];
		dp[s][e] = min(dp[s][e], solve(s, k) + solve(k + 1, e) + add);
	}
	return dp[s][e];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> mat[i][0] >> mat[i][1];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = 1e9;
		}
	}

	cout << solve(1, n) << endl;
}
