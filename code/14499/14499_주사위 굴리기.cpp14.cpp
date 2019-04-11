#include <iostream>
using namespace std;
#define endl '\n'

int map[21][21];
int dice[7];
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };


void rotate_dice(int dir) {
	if (dir == 1) {
		int tmp = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = tmp;
	}
	else if (dir == 2) {
		for (int i = 0; i < 3; i++) {
			int tmp = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = tmp;
		}
	}
	else if (dir == 3) {
		int tmp = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = tmp;
	}
	else if (dir == 4) {
		for (int i = 0; i < 3; i++) {
			int tmp = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = tmp;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int d;
		cin >> d;
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		x = nx;
		y = ny;

		rotate_dice(d);

		if (map[x][y] == 0) 
			map[x][y] = dice[6];
		else {
			dice[6] = map[x][y];
			map[x][y] = 0;
		}
		cout << dice[1] << endl;
	}
}