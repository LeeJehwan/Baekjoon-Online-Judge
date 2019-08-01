#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
#define endl '\n'
int n, m;
typedef pair<int, int> ii;
vector<ii> v2;
vector<ii> v1;
int dp[1005][1005];
ii track[1005][1005];
int dist(ii p1, ii p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void print(int x, int y) {
	if (x == 0 && y == 0)
		return;
	if (x == m && y == m)
		return;

	int t1 = track[x][y].first;
	int t2 = track[x][y].second;
	int s1 = x - t1;
	int s2 = y - t2;

	print(t1, t2);

	if (s1 == 0)
		cout << 2 << endl;
	else
		cout << 1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	v1.push_back({ 1,1 });
	v2.push_back({ n,n });
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v1.push_back({ a, b });
		v2.push_back({ a, b });
	}

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = 1e9;
		}
	}

	dp[1][0] = dist(v1[0], v1[1]);
	dp[0][1] = dist(v2[0], v2[1]);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) continue;
			int next = max(i, j) + 1;
			int t1 = dp[i][j] + dist(v1[i], v1[next]);
			if (dp[next][j] > t1) {
				dp[next][j] = t1;
				track[next][j] = { i,j };
			}
			int t2 = dp[i][j] + dist(v2[j], v2[next]);
			if (dp[i][next] > t2) {
				dp[i][next] = dp[i][j] + dist(v2[j], v2[next]);
				track[i][next] = { i,j };
			}
		}
	}
	int ans = 1e9;
	int sx, sy;
	for (int i = 0; i < m; i++) {
		if (ans > dp[i][m]) {
			ans = dp[i][m];
			sx = i;
			sy = m;
		}
	}
	for (int i = 0; i < m; i++) {
		if (ans > dp[m][i]) {
			ans = dp[m][i];
			sx = m;
			sy = i;
		}
	}
	cout << ans << endl;

	print(sx, sy);
}