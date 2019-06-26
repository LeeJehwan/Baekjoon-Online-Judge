#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

#define endl '\n'

int map[105][105][105];
int chk[105][105][105];
int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0 ,0, 0, 0, 1, -1 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, h;
	cin >> m >> n >> h;
	
	queue<tuple<int, int, int>> q;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin>>map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push(make_tuple(i, j, k));
					chk[i][j][k] = 1;
				}
				else if (map[i][j][k] == -1)
					chk[i][j][k] = -1;
			}
		}
	}

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx < 0 || nx >= n) continue;
			if (ny < 0 || ny >= m) continue;
			if (nz < 0 || nz >= h) continue;
			if (chk[nx][ny][nz] != 0) continue;
			
			chk[nx][ny][nz] = chk[x][y][z] + 1;
			q.push(make_tuple(nx, ny, nz));

		}
	}

	int ans = -1;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (chk[i][j][k] == 0) {
					cout << -1 << endl;
					return 0;
				}
				ans = max(ans, chk[i][j][k]);
			}
		}
	}
	cout << ans -1 << endl;

}