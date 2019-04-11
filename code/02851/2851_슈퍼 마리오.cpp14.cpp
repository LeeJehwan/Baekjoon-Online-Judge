#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int dp[11];
int dp2[11];
int main() {
	int arr[11];
	for (int i = 1; i <= 10; i++)
		cin >> arr[i];

	for (int i = 1; i <= 10; i++) {
		dp[i] = dp[i - 1] + arr[i];
		dp2[i] = abs(dp[i] - 100);
	}
	dp2[0] = 100;

	int k = 0;
	int ans = 101;
	for (int i = 0; i <= 10; i++) {
		if (ans == dp2[i])
			k = i;
		if (ans > dp2[i]) {
			ans = dp2[i];
			k = i;
		}
	}

	cout << dp[k] << endl;

}