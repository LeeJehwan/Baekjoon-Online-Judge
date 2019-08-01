#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
#define endl '\n'

char maze[1005][1005];
int fire_chk[1005][1005];
int jh_chk[1005][1005];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int main() {
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin >> m >> n;
		queue<pair<int, int>> jihoon;
		queue<pair<int, int>> fire;
		memset(maze,0,sizeof(maze));
		memset(jh_chk,0,sizeof(jh_chk));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				fire_chk[i][j] = -1;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf(" %c", &maze[i][j]);
				if (maze[i][j] == '@') {
					jihoon.push({ i,j });
					jh_chk[i][j] = 1;
				}
				else if (maze[i][j] == '*') {
					fire.push({ i,j });
					fire_chk[i][j] = 1;
				}
			}
		}


		while (!fire.empty()) {
			int fx = fire.front().first;
			int fy = fire.front().second;
			fire.pop();

			for (int i = 0; i < 4; i++) {
				int fdx = fx + dx[i];
				int fdy = fy + dy[i];
				if (fdx > 0 && fdx <= n && fdy > 0 && fdy <= m) {
					if (fire_chk[fdx][fdy] != -1)
						continue;
					if (maze[fdx][fdy] == '.' || maze[fdx][fdy] == '@') {
						fire_chk[fdx][fdy] = fire_chk[fx][fy] + 1;
						fire.push({ fdx,fdy });
					}
				}
			}
		}

		int ans = -1;
		while (!jihoon.empty()) {
			int jx = jihoon.front().first;
			int jy = jihoon.front().second;
			jihoon.pop();

			if (jx == 1 || jx == n || jy == 1 || jy == m) {
				ans = jh_chk[jx][jy];
				break;
			}

			for (int i = 0; i < 4; i++) {
				int jdx = jx + dx[i];
				int jdy = jy + dy[i];
				if (jdx > 0 && jdx <= n && jdy > 0 && jdy <= m) {
					if (maze[jdx][jdy] == '#')
						continue;
					if (jh_chk[jdx][jdy] != 0)
						continue;
					if (fire_chk[jdx][jdy] != -1 && fire_chk[jdx][jdy] <= jh_chk[jx][jy] + 1)
						continue;
					if (maze[jdx][jdy] == '.') {
						jh_chk[jdx][jdy] = jh_chk[jx][jy] + 1;
						jihoon.push({ jdx,jdy });
					}
				}
			}
		}

		if (ans == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
