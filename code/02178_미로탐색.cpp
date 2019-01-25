#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define endl '\n'

int maze[105][105];
int chk[105][105];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0 ,-1 };
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}

	queue<pair<int, int>> q;
	q.push({ 1,1 });
	chk[1][1] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
				if (chk[nx][ny] == 0 && maze[nx][ny] == 1) {
					chk[nx][ny] = chk[x][y] + 1;
					q.push({ nx,ny });
				}

			}
		}
	}
	cout << chk[n][m] << endl;

}
