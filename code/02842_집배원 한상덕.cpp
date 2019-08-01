#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define endl '\n'

char mat[51][51];
int h[51][51];
bool visit[51][51];
vector<int> v;
int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int sx, sy, n;

int dfs(int x, int y, int s, int e) {
	int ret = 0;
	if (h[x][y] < s || h[x][y] > e) return 0;

	visit[x][y] = true;
	if (mat[x][y] == 'K')
		ret = 1;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visit[nx][ny]) continue;
		if (nx < 0 || nx >= n) continue;

		if (ny < 0 || ny >= n)continue;
		ret += dfs(nx, ny, s, e);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int k_count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'P') {
				sx = i; sy = j;
			}
			if (mat[i][j] == 'K') {
				k_count++;
			}
		}
	}
	v.resize(n*n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> h[i][j];
			v[i*n + j] = h[i][j];
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int ans = v[v.size() - 1] - v[0];
	int s = 0, r = 0;
	while (s < v.size()) {
		while (1) {
			memset(visit, 0, sizeof(visit));
			if (dfs(sx, sy, v[r], v[s]) == k_count) {
				ans = min(ans, v[s] - v[r]);
				r++;
			}
			else
				break;
		}
		s++;
	}
	cout << ans << endl;
}
