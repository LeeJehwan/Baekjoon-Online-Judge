#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define endl '\n'

int dist[20][20];
int dp[20][100000];
int n;
int tsp(int cur, int visit) {
	if (visit == (1 << n) - 1) {
		if (dist[cur][0] == 0)
			return 1e9;
		return dist[cur][0];
	}
	if (dp[cur][visit] != 0) {
		return dp[cur][visit];
	}
	dp[cur][visit] = 1e9;
	for (int i = 0; i < n; i++) {
		if (visit & (1 << i)) continue;
		if (dist[cur][i] == 0) continue;
		dp[cur][visit] = min(dp[cur][visit], tsp(i, visit | (1 << i)) + dist[cur][i]);
	}
	return dp[cur][visit];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}
	cout << tsp(0, 1) << endl;
}