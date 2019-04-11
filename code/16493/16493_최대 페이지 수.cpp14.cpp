#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> day;
int dp[21][205];

void solve(int n, int m) {
	for (int i = 1; i <= m; i++) {
		int page = day[i - 1].second;
		int d = day[i - 1].first;
		for (int j = 1; j <= n; j++) {
			if (d > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j - d] + page, dp[i-1][j]);
		}
	}

}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int page, d;
		cin >> d >> page;
		day.push_back({ d,page });
	}
	solve(n, m);

	cout << dp[m][n] << endl;
}