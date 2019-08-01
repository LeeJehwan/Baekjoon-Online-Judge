#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int a[1001][1001];
int d[1001][1001];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int main() {
	queue <pair<int, int>> q;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			d[i][j] = -1;
			if (a[i][j] == 1) {
				q.push({ i,j });
				d[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny] == 0 && d[nx][ny] == -1) {
					q.push({ nx,ny });
					d[nx][ny] = d[x][y] + 1;
				}
			}
		}	
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != -1 && d[i][j] == -1) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (max < d[i][j])
				max = d[i][j];
		}
	}
	
	cout << max-1 << endl;
}