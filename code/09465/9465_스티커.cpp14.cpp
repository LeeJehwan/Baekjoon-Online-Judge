#include <iostream>
#include <algorithm>
using namespace std;

int dp[3][100001];
void solve() {

	int n;
	cin >> n;
	int arr[2][100001];
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= n; j++) {
			int tmp;
			cin >> tmp;
			arr[i][j] = tmp;
		}
	}
	dp[0][1] = 0;
	dp[1][1] = arr[0][1];
	dp[2][1] = arr[1][1];

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 2; j++) {
			dp[j][i] = dp[0][i-1];
			if (j == 0)
				dp[j][i] = max({ dp[0][i - 1],dp[1][i - 1], dp[2][i - 1] });
			if (j == 1)
				dp[j][i] = max(dp[j][i], dp[2][i - 1]) + arr[0][i];
			if (j == 2)
				dp[j][i] = max(dp[j][i], dp[1][i - 1]) + arr[1][i];
		}
	}
	int ans = max({ dp[0][n],dp[1][n],dp[2][n] });
	cout << ans << endl;

}



int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}