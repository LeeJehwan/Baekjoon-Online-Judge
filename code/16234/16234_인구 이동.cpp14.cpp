#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int n, L, R;
int map[52][52];
int chk[52][52];
int dx[4] = { -1 , 0, 1 , 0 };
int dy[4] = { 0, 1 , 0, -1 };

void bfs(int x, int y, int g) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	chk[x][y] = g;
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (chk[nx][ny]) continue;
			int diff = abs(map[fx][fy] - map[nx][ny]);
			if (diff < L || diff > R)
				continue;

			chk[nx][ny] = g;
			q.push({ nx,ny });
		}
	}
}


int main() {
	cin >> n >> L >> R;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	while (1) {
		memset(chk, 0, sizeof(chk));
		int cnt = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!chk[i][j])
					bfs(i, j, cnt++);
			}
		}
		if (cnt - 1 == n*n)
			break;

		vector<pair<int, int>> sum(cnt);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sum[chk[i][j]].first += map[i][j];
				sum[chk[i][j]].second++;
			}
		}
		vector<int> avg(cnt);
		for (int i = 1; i < cnt; i++) {
			avg[i] = sum[i].first / sum[i].second;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = avg[chk[i][j]];
			}
		}
		ans++;
	}

	cout << ans << endl;

}