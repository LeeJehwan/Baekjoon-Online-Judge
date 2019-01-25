#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define endl '\n'

int map[305][305];
int chk[305][305];
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main() {
	int t;
	cin >> t;

	while (t--) {
		memset(chk, 0, sizeof(chk));

		int n;
		cin >> n;
		int sx, sy;
		int ex, ey;
		cin >> sx >> sy >> ex >> ey;

		queue<pair<int, int>> q;
		q.push({ sx,sy });
		chk[sx][sy] = 1;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == ex && y == ey)
				break;

			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					if (chk[nx][ny] == 0) {
						q.push({ nx,ny });
						chk[nx][ny] = chk[x][y] + 1;
					}
				}
			}
		}
		cout << chk[ex][ey] - 1 << endl;
	}

}
