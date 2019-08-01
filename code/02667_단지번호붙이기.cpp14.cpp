#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n;
int input[30][30];
int d[30][30];
int ans[900];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

void dfs(int x, int y, int count) {
	d[x][y] = count;
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (ny >= 0 && ny < n && nx >= 0 && ny < n)
			if (input[nx][ny] == 1 && d[nx][ny] == 0)
				dfs(nx, ny, count);
	}
}


int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &input[i][j]);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (input[i][j] == 1 && d[i][j] == 0)
				dfs(i, j, ++cnt);
		}
	}
	cout << cnt << '\n';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(input[i][j])
				ans[d[i][j]] += 1;
		}
	}
	sort(ans + 1, ans + cnt + 1);
	for (int i = 1; i <= cnt; i++)
		cout << ans[i] << '\n';

}