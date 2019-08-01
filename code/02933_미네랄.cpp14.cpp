#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define endl '\n'

char map[105][105];
int chk[105][105];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0 , 1 };
vector<pair<int, int>> g;
int n, m;

void dfs(int x, int y) {
	if (map[x][y] == '.')
		return;
	if (chk[x][y])
		return;
	g.push_back(make_pair(x, y));
	chk[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			dfs(nx, ny);
	}
}


void simul() {
	memset(chk, 0, sizeof(chk));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '.')
				continue;
			if (chk[i][j] == true)
				continue;
			g.clear();
			dfs(i, j);

			int len = g.size();
			vector<int> low(m, -1);
			for (int k = 0; k < len; k++) {
				low[g[k].second] = max(low[g[k].second], g[k].first);
				map[g[k].first][g[k].second] = '.';
			}

			int max_low = n;
			for (int k = 0; k < m; k++) {
				if (low[k] == -1)
					continue;
				int h;
				for (h = low[k]; h < n && map[h][k] == '.' ; h++) {

				}
				max_low = min(max_low, h - low[k] - 1);
			}

			for (int k = 0; k < len; k++) {
				g[k].first += max_low;
				map[g[k].first][g[k].second] = 'x';
				chk[g[k].first][g[k].second] = 1;

			}

		}
	}




}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	int k;
	cin >> k;
	vector<int> v(k);
	for (int i = 0; i < k; i++) {
		int t;
		cin >> t;
		v[i] = n - t;
	}

	int dir = -1;
	for (int i = 0; i < k; i++) {
		if (dir == -1) {
			for (int j = 0; j < m; j++) {
				if (map[v[i]][j] == 'x') {
					map[v[i]][j] = '.';
					break;
				}
			}
			dir *= -1;
		}
		else {
			for (int j = m-1; j >= 0 ; j--) {
				if (map[v[i]][j] == 'x') {
					map[v[i]][j] = '.';
					break;
				}
			}
			dir *= -1;
		}
		simul();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	return 0;
}
