#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

vector<int> v[100005];
int low[100005];
int cnt = 0;
vector<pair<int, int>> e;

int dfs(int x, int p) {
	low[x] = ++cnt;
	int ret = low[x];
	for (auto node : v[x]) {
		if (node == p) continue;
		if (low[node]) {
			ret = min(ret, low[node]);
			continue;
		}
		int prev = dfs(node, x);
		if (prev > low[x]) {
			int a = node;
			int b = x;
			if (a > b) swap(a, b);
			e.push_back({ a, b });
		}
		ret = min(ret, prev);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1, 0);
	e.erase(unique(e.begin(), e.end()), e.end());
	sort(e.begin(), e.end());

	cout << e.size() << endl;
	for (auto x : e) {
		cout << x.first << ' ' << x.second << endl;
	}
}