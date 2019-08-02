#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int map[11][11];
int feed[11][11];
vector<int> tree[11][11];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = 5;
			cin >> feed[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a][b].push_back(c);
	}

	while (k--) {
		//spring & summer
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int v_size = tree[i][j].size();
				if (v_size == 0) continue;
				sort(tree[i][j].begin(), tree[i][j].end());
				for (int z = 0; z < v_size; z++) {
					if (map[i][j] < tree[i][j][z]) {
						for (int t = z; t < v_size; t++) {
							map[i][j] += tree[i][j][t] / 2;
						}
						tree[i][j].erase(tree[i][j].begin()+z, tree[i][j].end());
						break;
					}
					map[i][j] -= tree[i][j][z];
					tree[i][j][z]++;
				}
			}
		}
		//fall
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (auto it = tree[i][j].begin(); it != tree[i][j].end(); ++it) {
					if (*it % 5 == 0) {
						for (int z = 0; z < 8; z++) {
							int nx = i + dx[z];
							int ny = j + dy[z];
							if (nx < 1 || nx > n) continue;
							if (ny < 1 || ny > n) continue;
							tree[nx][ny].push_back(1);
						}
					}
				}
			}
		}
		//winter
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] += feed[i][j];
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum += tree[i][j].size();
		}
	}
	cout << sum << endl;
}
