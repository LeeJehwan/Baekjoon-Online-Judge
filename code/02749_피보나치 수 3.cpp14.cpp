#include <iostream>
using namespace std;


int dp[1500001];
int main() {
	long long n;
	cin >> n;

	n = n % 1500000;

	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;

	cout << dp[n] << '\n';
}