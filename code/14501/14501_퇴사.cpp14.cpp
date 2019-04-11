#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

int t[20];
int p[20];
int dp[30];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i], dp[i - 1]);
		dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
	}
	cout << max(dp[n],dp[n+1]) << endl;

}