#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define endl '\n'

int a[105];
long long dp[101][21];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	n--;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int sum;
	cin >> sum;

	dp[1][a[0]] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j - a[i - 1] >= 0)
				dp[i][j] += dp[i - 1][j - a[i - 1]];
			if (j + a[i - 1] <= 20)
				dp[i][j] += dp[i - 1][j + a[i - 1]];
		}
	}
	cout << dp[n][sum] << endl;
}