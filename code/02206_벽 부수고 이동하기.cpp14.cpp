#include <iostream>
#include <queue>
#include <cstdio>
#include <tuple>
using namespace std;
#define endl '\n'

char maze[1001][1001];
bool chk[1001][1001][2];
int dist[1001][1001];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

struct point{
	int x, y;
	int z; //벽을 부셨는지 안부셨는지의 상태
};


int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> maze[i][j];
		}
	}
	
	queue<point> q;
	point po;
	po.x = 1; po.y = 1; po.z = 0;
	q.push(po);

	chk[1][1][0] = true;
	dist[1][1] = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;

		q.pop();
		if (x == n && y == m)
			break;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m)
				continue;

			//다음 벽이 비어있는 상황이면 벽을 부시지 않고 진행
			if (maze[nx][ny] == '0') {
				if (chk[nx][ny][z] == false) {
					point po;
					po.x = nx; po.y = ny; po.z = z;
					q.push(po);
					chk[nx][ny][z] = true;
					dist[nx][ny] = dist[x][y] + 1;
				}
			}
			// 다음 벽이 벽인 경우 벽을 아직 안부셨으면 부셔보고 진행
			else {
				if (z == 0 && chk[nx][ny][z] == false) {
					point po;
					po.x = nx; po.y = ny; po.z = 1;
					q.push(po);
					chk[nx][ny][1] = true;
					dist[nx][ny] = dist[x][y] + 1;
				}
			}

		}
	}
	if (dist[n][m] == 0)
		cout << -1 << endl;
	else
		cout << dist[n][m] << endl;
}