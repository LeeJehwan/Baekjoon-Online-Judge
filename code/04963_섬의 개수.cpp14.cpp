#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int map[51][51];
int d[51][51];
int dx[] = { -1,-1,-1,0,1,1,1,0 };
int dy[] = { 1,0,-1,-1,-1,0,1,1 };
int w, h;
void dfs(int x, int y, int count) {
	d[x][y] = count;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
			if(map[nx][ny]==1 && d[nx][ny]==0)
				dfs(nx, ny, count);
		}
	}
}

int main() {
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%1d", &map[i][j]);
			}
		}

		int count = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (d[i][j] == 0 && map[i][j] == 1)
					dfs(i, j, ++count);
			}
		}
		cout << count << '\n';
		memset(map, 0, sizeof(map));
		memset(d, 0, sizeof(d));

	}
	return 0;
}