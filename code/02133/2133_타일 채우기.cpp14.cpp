#include <iostream>
using namespace std;

long long dp[31];
int main() {
	int n;
	cin >> n;

	dp[0] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = i; j >= 0; j = j - 2) {
			if (j >= 0)
				dp[i] = dp[i] + 2 * dp[j];
		}
		dp[i] += dp[i - 2];
	}

	cout << dp[n] << endl;
}