#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define endl '\n'

int tomato[1005][1005];
int chk[1005][1005];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0 ,1, -1 };
int main() {
	int m, n;
	cin >> m >> n;

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push({ i,j });
				chk[i][j] = 1;
			}
			if (tomato[i][j] == -1)
				chk[i][j] = -1;
		}
	}
	int ans = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		ans = max(ans, chk[x][y]);

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (tomato[nx][ny] == 0 && chk[nx][ny] == 0) {
					q.push({ nx,ny });
					chk[nx][ny] = chk[x][y] + 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chk[i][j] == 0) {
				ans = 0;
				break;
			}
		}
	}

	cout << ans - 1 << endl;
}