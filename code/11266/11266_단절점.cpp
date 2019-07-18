#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

vector<int> v[10001];
int low[10001];
bool ans[10001];
int cnt = 0;

int dfs(int x, bool root) {
	low[x] = ++cnt;
	int tmp_low = low[x];

	int child = 0;
	for (auto node : v[x]) {
		if (low[node]) {
			tmp_low = min(low[node], tmp_low);
			continue;
		}
		child++;

		int prev = dfs(node, false);
		if (!root && prev >= low[x]) {
			ans[x] = true;
		}
		tmp_low = min(prev, tmp_low);
	}
	if (root && child >= 2)
		ans[x] = true;
	return tmp_low;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!low[i])
			dfs(i, true);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += ans[i];
	}

	cout << cnt << endl;
	for (int i = 1; i <= n; i++)
		if (ans[i])
			cout << i << ' ';
	cout << endl;
}