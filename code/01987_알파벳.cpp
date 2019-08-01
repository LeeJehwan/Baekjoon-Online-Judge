#include <iostream>
#include <algorithm>
using namespace std;

int map[21][21];
int chk[50];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0 , 0, 1, -1 };
int ans = 0;
int n, m;

void go(int x, int y, int sum) {
	ans = max(ans, sum);
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n) continue;
		if (ny < 0 || ny >= m) continue;

		if (chk[map[nx][ny]] == 0) {
			chk[map[nx][ny]] = 1;
			go(nx, ny, sum + 1);
			chk[map[nx][ny]] = 0;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char t;
			cin >> t;
			map[i][j] = (int)(t - 'A');
		}
	}

	chk[map[0][0]] = 1;
	go(0, 0, 1);

	cout << ans << endl;
}