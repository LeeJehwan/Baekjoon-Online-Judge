#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

int map[501][501];
int dp[501][501];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0 , 0 , 1, -1 };
int n;

void dfs(int x, int y) {
	if (dp[x][y] == 0)
		dp[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n) continue;
		if (ny < 0 || ny >= n) continue;
		if (map[nx][ny] <= map[x][y]) continue;
		
		if (dp[nx][ny] == 0) dfs(nx, ny);
		dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);

	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(dp[i][j] == 0)
				dfs(i, j);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	
	cout << ans << endl;

}