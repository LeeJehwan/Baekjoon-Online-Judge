#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'

int m, n;
int map[51][51];
int room_area[2501];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
int chk[51][51];

int bfs(int sx, int sy, int room) {
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	chk[sx][sy] = room;
	
	int area = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		area++;
		for (int i = 0; i < 4; i++) {
			if (map[x][y] & (1 << i)) continue;
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
			if (chk[nx][ny] != 0) continue;

			q.push({ nx,ny });
			chk[nx][ny] = room;
		}
	}
	return area;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	int room = 0;
	int max_area = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (chk[i][j] == 0) {
				room++;
				max_area = max(max_area, room_area[room] = bfs(i, j, room));
			}
		}
	}
	int max_area2 = max_area;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 4; k++) {
				if (map[i][j] & (1 << k)) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
					if (chk[i][j] == chk[nx][ny]) continue;
					max_area2 = max(max_area2, room_area[chk[i][j]] + room_area[chk[nx][ny]]);
				}
			}
		}
	}
	cout << room << endl;
	cout << max_area << endl;
	cout << max_area2 << endl;
}