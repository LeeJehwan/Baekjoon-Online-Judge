#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
const int MAX_N = 200001;
const int LGN = 20;
vector<int> adj[MAX_N];
int lv[MAX_N], parent[MAX_N][LGN], chk[MAX_N];

void dfs(int here) {
	chk[here] = 1;

	int next;
	for (int i = 0; i < (int)adj[here].size(); i++) {
		next = adj[here][i];
		if (chk[next]) continue;

		lv[next] = lv[here] + 1;

		parent[next][0] = here;
		for (int j = 1; j < LGN; j++) {
			parent[next][j] = parent[parent[next][j - 1]][j - 1];
		}

		dfs(next);
	}
}

int lca(int a, int b) {
	if (lv[a] < lv[b]) swap(a, b);

	for (int i = LGN - 1; i >= 0; i--) {
		if (lv[a] - lv[b] >= (1 << i)) {
			a = parent[a][i];
		}
	}

	if (a == b) return a;
	for (int i = LGN - 1; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int m;
	cin >> m;
	lv[1] = 0;
	dfs(1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << endl;
	}


}