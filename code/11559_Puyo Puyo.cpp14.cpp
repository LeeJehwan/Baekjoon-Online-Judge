#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define endl '\n'

char map[12][6];
bool chk[12][6];
bool down[6];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	chk[sx][sy] = true;
	
	vector<pair<int, int>> v;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		v.push_back({ x,y });

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
			if (map[x][y] != map[nx][ny]) continue;
			if (map[nx][ny] == '.') continue;
			if (chk[nx][ny] != 0) continue;

			chk[nx][ny] = true;
			q.push({ nx,ny });
		}
	}

	if (v.size() >= 4) {
		for (auto x : v) {
			map[x.first][x.second] = '.';
			down[x.second] = true;
		}
		return true;
	}
	return false;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	while (1) {
		memset(chk, 0, sizeof(chk));
		int count = 0;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (chk[i][j] == false && map[i][j] !='.') {
					count += bfs(i, j);
				}
			}
		}
		if (count == 0) break;

		for (int i = 0; i < 6; i++) {
			if (down[i] == false) continue;

			int up = 0;
			for (int j = 11; j >= 0; j--) {
				if (map[j][i] == '.')
					up++;
				else if(up != 0){
					map[j + up][i] = map[j][i];
					map[j][i] = '.';
				}
			}
		}

		ans++;
	}
	cout << ans << endl;
}