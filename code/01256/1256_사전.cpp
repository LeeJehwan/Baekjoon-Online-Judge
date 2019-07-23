#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

long long dp[201][201];
void comb() {
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) dp[i][j] = 1;
			else if (i == j) dp[i][j] = 1;
			else
				dp[i][j] = min(dp[i - 1][j - 1] + dp[i - 1][j], (long long)1e9 + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	comb();
	int total = n + m;
	if (dp[total][m] < k) {
		cout << -1 << endl;
		return 0;
	}

	while (n != 0 || m != 0) {
		if (n == 0) {
			cout << 'z';
			m--;
		}
		else if (m == 0) {
			cout << 'a';
			n--;
		}
		else if (dp[n + m - 1][n - 1] < k) {
			k -= dp[n + m - 1][n - 1];
			cout << 'z';
			m--;
		}
		else {
			cout << 'a';
			n--;
		}
	}

}
