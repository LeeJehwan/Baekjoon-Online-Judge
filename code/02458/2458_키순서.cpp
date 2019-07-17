#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define INF 50000000

int map[501][501];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		map[u][v] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		bool flag = true;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (map[i][j] == INF && map[j][i] == INF) {
				flag = false;
				break;
			}
		}
		if (flag) ans++;
	}

	cout << ans << endl;
}