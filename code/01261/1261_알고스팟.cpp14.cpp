#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;
#define endl '\n'

int arr[101][101];
bool chk[101][101];
int ans[101][101];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int main() {
	int n, m;
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	//n->first y
	//m->second x 

	deque<pair<int,int>> q;
	q.push_back({ 0,0 });
	chk[0][0] = true;

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop_front();

		if (x == m-1 && y == n-1)
			break;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (chk[ny][nx] == false) {
					if (arr[ny][nx] == 0) {
						q.push_front({ ny,nx });
						ans[ny][nx] = ans[y][x];
						chk[ny][nx] = true;
					}
					else if (arr[ny][nx] == 1) {
						q.push_back({ ny,nx });
						ans[ny][nx] = ans[y][x] + 1;
						chk[ny][nx] = true;
					}
				}
			}

		}
	}
	cout << ans[n - 1][m - 1] << endl;

}
