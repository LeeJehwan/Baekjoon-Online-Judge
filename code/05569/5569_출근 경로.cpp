#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 100000

int map[105][105];
int dp1[2][105][105];
int dp2[2][105][105];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> m >> n;

	for (int i = 1; i <= n; i++) {
		map[i][1] = 1;
		dp2[0][i][1] = 1;
	}

	for (int i = 1; i <= m; i++) {
		map[1][i] = 1;
		dp1[0][1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			dp1[0][i][j] = (dp1[0][i][j - 1] + dp1[1][i][j - 1]) % MOD;
			dp1[1][i][j] = dp2[0][i][j - 1] % MOD;
			dp2[0][i][j] = (dp2[0][i - 1][j] + dp2[1][i - 1][j]) % MOD;
			dp2[1][i][j] = dp1[0][i - 1][j] % MOD;
		}
	}
	long long ans = dp1[0][n][m] + dp1[1][n][m] + dp2[0][n][m] + dp2[1][n][m];
	cout << ans % MOD << endl;

}