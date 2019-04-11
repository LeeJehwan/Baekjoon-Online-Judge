#include <iostream>
using namespace std;

int dp[15][15];
void bin(int n, int k) {
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= k; j++)
			if (j == 0 || i == j)
				dp[i][j] = 1;
	
	for (int i = 2; i <= n; i++)
		for (int j = 1 ; j <= k; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];


}

int main() {
	int n, k;
	cin >> n >> k;
	bin(n, k);
	cout << dp[n][k] << endl;
	return 0;
}