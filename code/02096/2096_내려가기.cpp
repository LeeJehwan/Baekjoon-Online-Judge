#include <iostream>
#include <algorithm>
using namespace std;


int map[100001][3];
int dp[2][3];
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
		dp[0][i] = map[0][i];


	for (int i = 1; i < n; i++) {
		dp[1][0] = max(dp[0][0], dp[0][1]) + map[i][0];
		dp[1][1] = max({ dp[0][0], dp[0][1], dp[0][2] }) + map[i][1];
		dp[1][2] = max(dp[0][1], dp[0][2]) + map[i][2];
		dp[0][0] = dp[1][0];
		dp[0][1] = dp[1][1];
		dp[0][2] = dp[1][2];
	}
	int ans1 = max({ dp[0][0], dp[0][1], dp[0][2] });

	for (int i = 0; i < 3; i++) {
		dp[0][i] = map[0][i];
	}

	for (int i = 1; i < n; i++) {
		dp[1][0] = min(dp[0][0], dp[0][1]) + map[i][0];
		dp[1][1] = min({ dp[0][0], dp[0][1], dp[0][2] }) + map[i][1];
		dp[1][2] = min(dp[0][1], dp[0][2]) + map[i][2];
		dp[0][0] = dp[1][0];
		dp[0][1] = dp[1][1];
		dp[0][2] = dp[1][2];
	}
	int ans2 = min({ dp[0][0], dp[0][1], dp[0][2] });

	cout << ans1 << " " << ans2 << endl;
}
