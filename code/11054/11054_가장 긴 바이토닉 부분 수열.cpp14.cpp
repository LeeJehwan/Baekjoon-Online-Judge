#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int dp2[1001];
int main() {
	int n;
	cin >> n;

	int arr[1001];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	for (int i = n; i > 0 ; i--) {
		dp2[i] = 1;
		for (int j = n; j > i; j--) {
			if (arr[i] > arr[j])
				dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i] + dp2[i] - 1);
	}

	cout << ans << endl;

}