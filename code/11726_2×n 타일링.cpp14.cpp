#include <iostream>
using namespace std;

int mod = 10007;
int dp[1001];
int tiling(int num) {
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= num; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])%mod;
	}
	return dp[num];
}
int main() {
	int num;
	cin >> num;

	cout << tiling(num) << endl;
}