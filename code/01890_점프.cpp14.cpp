#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define endl '\n'

long long dp[101][101];
int main() {
	int n;
	cin >> n;

	int jump[101][101];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> jump[i][j];
		}
	}
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int k = jump[i][j];
			if (i == n && j == n)
				break;
			if (dp[i][j] != 0) {
				if (k + i <= n) {
					dp[i + k][j] += dp[i][j];
				}
				if (k + j <= n) {
					dp[i][j + k] += dp[i][j];
				}
			}
		}
	}

	cout << dp[n][n] << endl;
}