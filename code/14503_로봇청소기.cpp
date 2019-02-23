#include <iostream>
using namespace std;
#define endl '\n'

int map[51][51];
bool chk[51][51];
int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c, sx, sy, d;
	cin >> r >> c;
	cin >> sx >> sy >> d;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
	int cnt = 0;
	int x = sx, y = sy;
	while (1) {
		if (chk[x][y] == 0 && map[x][y] == 0) {
			chk[x][y] = 1;
			cnt++;
		}
		bool go = false;
		int nd = d;
		for (int i = 0; i < 4; i++) {
			nd = (nd + 3) % 4;
			int nx = x + dx[nd];
			int ny = y + dy[nd];
			if (chk[nx][ny] == 0 && map[nx][ny] == 0) {
				x = nx;
				y = ny;
				d = nd;
				go = true;
				break;
			}
			if (i == 3) {
				x = x + dx[(d + 2) % 4];
				y = y + dy[(d + 2) % 4];
				if (map[x][y] == 0) {
					go = true;
				}
			}
		}
		if (go) continue;
		else break;
	}
	cout << cnt << endl;
}