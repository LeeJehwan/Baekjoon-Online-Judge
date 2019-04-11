#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
#define endl '\n'

int dp[31][31];
void bin(int n, int k) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i == 1 || j == 1 || i == j)
				dp[i][j] = 1;
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
	}
}



int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	bin(n, k);
	cout << dp[n][k] << endl;
}