#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define endl '\n'

int dp[1005][1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str1, str2;
	cin >> str1 >> str2;
	int n = str1.size();
	int m = str2.size();

	int ans = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (str1[j - 1] == str2[i - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
}

