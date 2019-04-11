#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101][32];

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	int k;
	cin >> k;

	for (int i = 1; i <= 31; i++) {
		dp[0][i] = k;
	}

	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) {
		int start = v[i - 1].first;
		int end = v[i - 1].second;
		for (int j = 1; j <= 31; j++) {
			if (j < start)
				dp[i][j] = dp[i - 1][j];
			else if (j >= start && j < end)
				dp[i][j] = dp[i - 1][j] - 1;
			else if (j >= end)
				dp[i][j] = dp[i-1][j];
			if (dp[i][j] < 0) {
				cout << 0 << endl;
				return 0;
			}
		}
	}
	cout << 1 << endl;
}