#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000005];
int a[1000005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int idx = 0;
	dp[0] = a[0];
	for (int i = 1; i < n; i++) {
		if (dp[idx] < a[i]) {
			dp[++idx] = a[i];
		}
		else {
			auto ii = lower_bound(dp, dp + idx, a[i]);
			dp[ii - dp] = a[i];
		}
	}
	cout << idx + 1 << endl;
}