#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
const int MAX_N = 50001;
vector<int> adj[MAX_N];
int lv[MAX_N], parent[MAX_N], chk[MAX_N];

void dfs(int here) {
	chk[here] = 1;

	int next;
	for (int i = 0; i < (int)adj[here].size(); i++) {
		next = adj[here][i];
		if (chk[next]) continue;

		lv[next] = lv[here] + 1;
		parent[next] = here;
		dfs(next);
	}
}

int lca(int a, int b) {
	if (lv[a] < lv[b]) swap(a, b);

	while (lv[a] != lv[b]) {
		a = parent[a];
	}

	if (a == b) return a;

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
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