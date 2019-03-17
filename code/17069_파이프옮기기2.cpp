#include <iostream>
using namespace std;
#define endl '\n'


long long dp[33][33][3];
int map[33][33];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 2; i <= n; i++) {
		if (map[1][i])
			break;
		dp[1][i][0] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 3; j <= n; j++) {
			if (!map[i][j]) {
				dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
				dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
				if(!map[i-1][j] && !map[i][j-1])
					dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
			}
		}
	}

	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2] << endl;

}