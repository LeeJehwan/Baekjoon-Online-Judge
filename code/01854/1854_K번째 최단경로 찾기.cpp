#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'

vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>> pq;
int ans[1001];
int cnt[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}

	pq.push({ 0, 1 });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (cnt[node] == k) continue;
		cnt[node]++;
		if (cnt[node] == k)
			ans[node] = cost;

		for (auto next : v[node]) {
			pq.push({ -(cost + next.second), next.first });
		}
	}

	for (int i = 1; i <= n; i++) {
		if (cnt[i] < k) {
			cout << -1 << endl;
		}
		else
			cout << ans[i] << endl;
	}
}