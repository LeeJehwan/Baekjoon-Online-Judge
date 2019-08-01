#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
#define endl '\n'

int dp[1005][1005];
int track[1005][1005];
// 1 -> left
// 2 -> up
// 3 -> dig
string str1, str2;


void print(int i, int j) {
	if (track[i][j] == 0)
		return;

	int t = track[i][j];
	if (t == 1) print(i, j - 1);
	if (t == 2) print(i - 1, j);
	if (t == 3) {
		print(i - 1, j - 1);
		cout << str1[j - 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str1 >> str2;
	int n = str1.size();
	int m = str2.size();

	int ans = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (str1[j - 1] == str2[i - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				track[i][j] = 3;
			}
			else {
				if (dp[i - 1][j] > dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
					track[i][j] = 2;
				}
				else {
					dp[i][j] = dp[i][j - 1];
					track[i][j] = 1;
				}
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	print(m, n);
}

