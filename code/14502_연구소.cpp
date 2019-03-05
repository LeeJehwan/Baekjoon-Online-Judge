#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define endl '\n'

int n, m;
int map[10][10];
int dx[] = { -1, 1, 0 , 0 };
int dy[] = { 0 , 0, -1 ,1 };
int ans = 0;
int map2[10][10];

void cal() {
    int	count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map2[i][j] == 0)
				count++;
		}
	}
	ans = max(ans, count);
}

void bfs() {
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			map2[i][j] = map[i][j];
			if (map[i][j] == 2)
				q.push({ i,j });
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
			if (map2[nx][ny] == 0) {
				q.push({ nx,ny });
				map2[nx][ny] = 2;
			}
		}
	}

}


void go(int num, int x, int y) {
	if (num == 3) {
		bfs();
		cal();
		
		return;
	}

	for (int i = x ; i <= n; i++) {
		int j = 1;
		if (i == x)
			j = y + 1;
		for (; j <= m; j++) {

			if (map[i][j] == 0) {
				map[i][j] = 1;
				go(num+1, i, j);
				map[i][j] = 0;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				go(1, i, j);
				map[i][j] = 0;
			}
		}
	}


	cout << ans << endl;
}