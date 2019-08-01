#include <iostream>
using namespace std;

int dp[1005];
int main() {
	int n;
	cin >> n;

	int arr[1005];
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (dp[i] < dp[i - j] + arr[j])
				dp[i] = dp[i - j] + arr[j];
		}
	}

	cout << dp[n] << endl;
}