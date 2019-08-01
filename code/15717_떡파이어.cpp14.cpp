#include <iostream>
using namespace std;
#define mod 1000000007
long long dp[10000005];

long long fire(long long ret, long long n) {
	if (n < 60) {
		if (dp[n] == 0)
			return dp[n] = (ret << n) % mod;
		else
			return dp[n];
	}

	if (n < 10000000) {
		if (dp[n] == 0)
			if (n % 2 == 0) 
				dp[n] = (((fire(ret, n / 2)) % mod)* ((fire(ret, n / 2)) % mod)) % mod;
			else
				dp[n]= (((fire(ret, n / 2)) % mod)* ((fire(ret, n / 2+1)) % mod)) % mod;
		return dp[n];
	}
	if (n % 2 == 0)
		return (((fire(ret, n / 2)) % mod)* ((fire(ret, n / 2)) % mod)) % mod;
	else
		return (((fire(ret, n / 2)) % mod)* ((fire(ret, n / 2 + 1)) % mod)) % mod;
}

int main() {
	long long n;
	cin >> n;
	if (n == 0) {
		cout << 1 << endl;
		return 0;
	}

	cout << fire(1, n - 1) % mod << endl;
}