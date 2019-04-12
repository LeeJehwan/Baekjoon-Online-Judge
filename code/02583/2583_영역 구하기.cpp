#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int map[101][101];
bool chk[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	chk[sx][sy] = 1;
	
	int area = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;	
		q.pop();
		area++; 
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
			if (chk[nx][ny] != 0) continue;
			if (map[nx][ny] == 1) continue;

			q.push({ nx,ny });
			chk[nx][ny] = 1;
		}
	}
	return area;
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		for (int i = ly+1; i <= ry; i++) {
			for (int j = lx+1; j <= rx; j++) {
				map[i][j] = 1;
			}
		}
	}
	int cnt = 0;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (chk[i][j] == 0 && map[i][j] == 0) {
				v.push_back(bfs(i, j));
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	sort(v.begin(), v.end());
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;

}