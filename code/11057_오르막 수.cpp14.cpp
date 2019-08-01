#include <iostream>
using namespace std;
#define MOD 10007
int dp[1005][10];

int main() {
	int n;
	cin >> n;
	int sum = 0;

	for (int i = 1; i <= n; i++)
		dp[i][9] = 1;

	for (int i = 1; i <= n; i++) 
		for (int j = 8; j >= 0; j--)
			dp[i][j] = (dp[i][j + 1] + dp[i - 1][j])%MOD;

	for (int i = 0; i <= 9; i++)
		sum = (sum + dp[n][i]) % MOD;

	cout << sum << endl;
}