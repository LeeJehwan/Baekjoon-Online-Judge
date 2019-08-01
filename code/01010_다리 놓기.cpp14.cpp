#include <iostream>
using namespace std;

int dp[35][35];

void bino(int n, int r) {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= r; j++) {
			if (j == 0) {
				dp[i][j] = 1;
				continue;
			}
			if (i == j) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	cout << dp[n][r] << endl;
}

void run() {
	int n, r;
	cin >> r >> n;
	bino(n, r);
}

int main() {
	int tcase;
	cin >> tcase;

	for (int i = 0; i < tcase; i++) {
		run();
	}
}