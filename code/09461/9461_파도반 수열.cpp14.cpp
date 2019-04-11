#include <iostream>
using namespace std;

int main() {
	long long dp[105];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	int t;
	cin >> t;
	while (t--) {
		int temp; 
		cin >> temp;
		for (int i = 6; i <= temp; i++)
			dp[i] = dp[i - 1] + dp[i - 5];
		cout << dp[temp] << endl;
	}
}