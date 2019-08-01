#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define endl '\n'

int dp[4005][4005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str1, str2;
	cin >> str1 >> str2;

	int n = str1.size();
	int m = str2.size();

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = max(dp[i][j], ans);
			}
		}
	}
	cout << ans << endl;
}