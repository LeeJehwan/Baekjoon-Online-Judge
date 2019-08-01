#include <iostream>
#include <queue>
using namespace std;

bool a[100][100];
int d[100][100];
int dis[100][100];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && d[i][j] == 0) 
			{
				d[i][j] = ++cnt;
				queue<pair<int, int>> q;
				q.push({ i,j });
				while (!q.empty()) 
				{
					int tx = q.front().first;
					int ty = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++)
					{
						int nx = tx + dx[i];
						int ny = ty + dy[i];
						if (nx >= 0 && nx < n && ny >= 0 && ny < n) 
						{
							if (d[nx][ny] == 0 && a[nx][ny] == 1) 
							{
								q.push({ nx,ny });
								d[nx][ny] = cnt;
							}
						}
					}
				}
			}	
		}
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dis[i][j] = -1;
			if (a[i][j] == 1) {
				q.push({ i,j });
				dis[i][j] = 0;
			}
		}
	}

	int ans = -1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n&& ny < n && ny >= 0) {
				if (dis[nx][ny] == -1) {
					q.push({ nx,ny });
					dis[nx][ny] = dis[x][y] + 1;
					d[nx][ny] = d[x][y];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx >= 0 && nx < n&& ny < n && ny >= 0) {
					if (d[nx][ny] != d[i][j]) {
						if (ans == -1 || ans > dis[nx][ny] + dis[i][j])
							ans = dis[nx][ny] + dis[i][j];
					}
				}
			}
		}
	}
	cout << ans << endl;

}