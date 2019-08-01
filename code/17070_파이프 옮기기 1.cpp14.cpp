#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'

struct pipe {
	int x, y;
	int lx, ly;
};

int map[20][20];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	queue<pipe> q;
	if (map[1][1] == 0 && map[1][2] == 0) {
		pipe pip;
		pip.x = 1; pip.y = 2; pip.lx = 1; pip.ly = 1;
		q.push(pip);
	}
	
	int ans = 0;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		if (p.x == n && p.y == n) {
			ans += 1;
		}

		int dx = p.x - p.lx;
		int dy = p.y - p.ly;
		if (dx == 1 && dy == 0) {
			int nx = p.x + 1;
			int ny = p.y;
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
				if (!map[nx][ny]) {
					pipe pip;
					pip.x = nx; pip.y = ny; pip.lx = p.x; pip.ly = p.y;
					q.push(pip);
				}
			}
			ny = p.y + 1;
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
				if (!map[p.x+1][p.y+1] && !map[p.x][p.y+1] && !map[p.x+1][p.y]) {
					pipe pip;
					pip.x = nx; pip.y = ny; pip.lx = p.x; pip.ly = p.y;
					q.push(pip);
				}
			}
		}
		else if (dx == 0 && dy == 1) {
			int nx = p.x + dx;
			int ny = p.y + dy;
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
				if (!map[nx][ny]) {
					pipe pip;
					pip.x = nx; pip.y = ny; pip.lx = p.x; pip.ly = p.y;
					q.push(pip);
				}
			}
			nx += 1;
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
				if (!map[p.x + 1][p.y + 1] && !map[p.x][p.y + 1] && !map[p.x + 1][p.y]) {
					pipe pip;
					pip.x = nx; pip.y = ny; pip.lx = p.x; pip.ly = p.y;
					q.push(pip);
				}
			}
		}
		else if (dx == 1 && dy == 1) {
			int nx = p.x + 1;
			int ny = p.y;
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
				if (!map[nx][ny]) {
					pipe pip;
					pip.x = nx; pip.y = ny; pip.lx = p.x; pip.ly = p.y;
					q.push(pip);
				}
			}
			nx = p.x;
			ny = p.y + 1;
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
				if (!map[nx][ny]) {
					pipe pip;
					pip.x = nx; pip.y = ny; pip.lx = p.x; pip.ly = p.y;
					q.push(pip);
				}
			}
			nx = p.x + 1;
			ny = p.y + 1;
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
				if (!map[p.x + 1][p.y + 1] && !map[p.x][p.y + 1] && !map[p.x + 1][p.y]) {
					pipe pip;
					pip.x = nx; pip.y = ny; pip.lx = p.x; pip.ly = p.y;
					q.push(pip);
				}
			}
		}
	}
	cout << ans << endl;

}