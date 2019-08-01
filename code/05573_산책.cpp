#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int map[1005][1005];
int dp[1005][1005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	//0: 아래, 1: 오른쪽

	dp[1][1] = k - 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i + 1][j] += dp[i][j] / 2;
			dp[i][j + 1] += dp[i][j] / 2;
			if (dp[i][j] % 2 != 0) {
				if (map[i][j]) dp[i][j + 1]++;
				else dp[i + 1][j]++;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			map[i][j] = (map[i][j] + dp[i][j]) % 2;
		}
	}
	int sx = 1, sy = 1;
	while (1) {
		if (map[sx][sy] == 1) {
			sy++;
		}
		else {
			sx++;
		}
		if (sx == n + 1 || sy == m + 1)
			break;
	}
	cout << sx << " " << sy << endl;

}